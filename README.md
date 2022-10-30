# ABOUT

- Implementation of Ant Colony Optimization for edge detection as a Numpy-dependent python library using Numpy-API

# INSTALLATION

- Install numpy and matplotlib
- Run `numpy.__path__`
- Compile alg.c as shared with local install of python & the numpy/core/include of numpy as found above. Use -fPIC flag to force it.
- Create a `makefile` to automate this. `Bear` can be use to make config files for auto-suggest 
- Make sure the file is .png
- al.py will give a meta-edge by combining all streams and al2.py will give edge for a selected stream of chroma only
