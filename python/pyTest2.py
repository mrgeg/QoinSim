import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import PyQoinSim
import csv

random 	= PyQoinSim.RandomVarInt()

pathNumber = 5

paths = random.getProcess(["TYPE:OrnUhlen"], 2.0, 10000, pathNumber)

for i in range(1,pathNumber+1):
	plt.plot(paths[0], paths[i])

plt.show()