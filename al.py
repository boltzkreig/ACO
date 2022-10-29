import alg
import numpy as np
import matplotlib.image as img

file=input("ENTER FILE NAME:")
a = img.imread(file)
b = a.transpose(2,0,1)
c0= b[0,:,:].astype(float)
c1= b[1,:,:].astype(float)
c2= b[2,:,:].astype(float)

ants = int(input("Number of Ants:     "))
interation = int(input("Interation:    "))
neighbour = int(input("Neighbour( between 1 to 8):        "))
sensitivity = float(input("Sensitivity( between 0 to 1):        "))

sh = c0.shape

d0 = alg.aco(c0, ants, interation, neighbour, sensitivity)
d1 = alg.aco(c1, ants, interation, neighbour, sensitivity)
d2 = alg.aco(c2, ants, interation, neighbour, sensitivity)

e0 = d0.reshape(sh[0],sh[1])
e1 = d1.reshape(sh[0],sh[1])
e2 = d2.reshape(sh[0],sh[1])

f = np.array([e0,e1,e2])
f = f.transpose(1,2,0)

name = file.replace(".png","") + "(" + str(ants) + "," + str(interation) + "," + str(neighbour) + "," + str(sensitivity) + ")_edges.png"
img.imsave(name, f)
