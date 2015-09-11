import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import PyQoinSim
import csv

random 	= PyQoinSim.RandomVarInt()

paths = random.getProcess(["TYPE:Poisson"], 1.0, 100, 2)