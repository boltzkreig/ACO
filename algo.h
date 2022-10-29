#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
	int x;
	int y;
}insect;
//arr, ants, iter, neig, sens

int pos(int x, int y, int x_max, int y_max){
	if(x < 0 || y < 0 || x >= x_max || y >= y_max){
		return -1;
	}
	return (y*x_max)+x;
}

double *optimize(double *data,long *shape,int size, int ants ,int iter, int neig, double sens){
	//double * c_arr		=calloc(size, sizeof(double));
	double * Phe_Mat	=calloc(size, sizeof(double));
	insect * ANT 		= calloc(ants,sizeof(insect));
	//srand(time(0));
	int i,l,h,dl,dh,n,index,curr_x, curr_y, tally, x,  y;
	l	=(int)shape[0];
	h	=(int)shape[1];

	// l=y	h=x
/***********************INITIALIZATION******************************/
	for (i=0; i<ants; ++i){
		ANT[i].x=rand()%h;
		ANT[i].y=rand()%l;
	}

// Iterations are run; each iteration goes through position of each ant
	for(n=0; n < iter; n++){
		for ( i=0; i < ants; i++){
            //assigns direction to ant movement
			tally=0;
			dl=(rand()%3)-1;
			dh=(rand()%3)-1;

            //If found at border of frame it stops and forces inside if possible
			if(ANT[i].x==0){
				dh=abs(dh);
			}else if(ANT[i].x==(h-1)){
				dh=-abs(dh);
			}
			if(ANT[i].y==0){
				dl=abs(dl);
			}else if(ANT[i].y==(l-1)){
				dl=-abs(dl);
			}

			//notes the position and update it for next iteration
			//This makes the code readable at the cost of a small storage space
			curr_x=ANT[i].x;
			curr_y=ANT[i].y;
			ANT[i].x+=dh;
			ANT[i].y+=dl;

			for(x=curr_x-1; x<=curr_x+1; x++){for(y=curr_y-1; y<=curr_y+1; y++){
				if(pos(x, y,h,l)==-1) continue;
				if(fabs(data[pos(x,y,h,l)] - data[pos(curr_x,curr_y,h,l)]) <= sens){
					tally++;
				}}}
			if(tally <= neig){
				Phe_Mat[pos(curr_x,curr_y,h,l)]=1.0;
			}
		}
	}

	free(ANT);
	return Phe_Mat;
}
