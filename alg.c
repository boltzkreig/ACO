#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <numpy/arrayobject.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "algo.h"

PyObject *ACO(PyObject *self, PyObject *args){
	PyArrayObject  *arr;
	int ants, iter, neig;
	double sens;

	PyArg_ParseTuple(args, "Oiiid", &arr, &ants, &iter, &neig, &sens);
	if(PyErr_Occurred()){printf("Parse Error\n");return NULL;}

	double *data		= PyArray_DATA(arr);
	long *shape			= PyArray_SHAPE(arr);
	int size			= PyArray_SIZE(arr);
	long si_ze[]		= { [0] = size };
	int dim				= PyArray_NDIM(arr);
	PyObject *result	= PyArray_SimpleNew(1,si_ze ,NPY_DOUBLE);
	double *result_data = PyArray_DATA((PyArrayObject*)result);
	//the next line will do what ever it does
	double *inter_data	= optimize(data, shape, size, ants, iter, neig, sens);
	for (int i =0;i < size; ++i){
		result_data[i]	= inter_data[i];
	}
	//c-arr must be freed but don't know how
	return result;
}
/*****************************ALL METHODS*************************************/
static PyMethodDef methods[] = {
	{ "aco", ACO, METH_VARARGS, "does something for sure" },
	{ NULL, NULL, 0, NULL }
};
/*********ABSOLUTELY BOILER-PLATE DON'T TRY TO CHANGE ANYTHING BELOW**********/
static struct PyModuleDef alg = {
	PyModuleDef_HEAD_INIT,
	"alg",
	"This is supposed to do ACO Iterations",
	-1,
	methods
};
/**************************MAIN EQUIVALENT************************************/
PyMODINIT_FUNC PyInit_alg(){
	printf("Loaded");
	PyObject *module = PyModule_Create(&alg);
	import_array();
	return module;
}
