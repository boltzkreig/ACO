import alg
import numpy as np
import matplotlib.image as img

file=input("ENTER FILE NAME:")

color = {"r":0, "g":1, "b":2}
i = input("stream(r/g/b):")
a = img.imread(file)
b = a.transpose(2,0,1)
c0= b[color[i],:,:].astype(float)

ants = int(input("Number of Ants:"))
interation = int(input("Interation:"))
neighbour = int(input("Neighbour( between 1 to 8):"))
sensitivity = float(input("Sensitivity( between 0 to 1):"))

print("Will analysis only one stream")
d0 = alg.aco(c0, ants, interation, neighbour, sensitivity)
sh = c0.shape
e0 = d0.reshape(sh[0],sh[1])
f0 = np.array([e0,e0,e0])
f0 = f0.transpose(1,2,0)

name = file.replace(".png","") + "(" + str(ants) + "," + str(interation) + "," + str(neighbour) + "," + str(sensitivity) + ")_" + i + "_edges.png"
img.imsave(name, f0)
