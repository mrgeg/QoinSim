import matplotlib.pyplot as plt
import PyQoinSim

random 	= PyQoinSim.RandomVarInt()

x = random.getRandom(["TYPE:UniformMT"], 10000)
y = random.getRandom(["TYPE:UniformMT"], 10000)

plt.scatter(x,y)
plt.show()

x1 = random.getRandom(["TYPE:UniformSobol","SOBOLDIM:1100"], 1100)
y1 = random.getRandom(["TYPE:UniformSobol","SOBOLDIM:1100"], 1100)

plt.scatter(x1,y1)
plt.show()
