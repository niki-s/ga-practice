# Used for assignment 3 in CS776 by Niki Silveria Sept 22, 2017
# https://www.cse.unr.edu/~sushil/class/gas/code/cplus/

import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("outfile_177")
x, y = data[:, 0], data[:,3]

plt.plot(x, y, linewidth=2.0)
plt.show()
