import matplotlib.pyplot as plt
import PyQoinSim

random 	= PyQoinSim.RandomVarInt()

x = random.getRandom(["TYPE:UniformMT"], 10000)
y = random.getRandom(["TYPE:UniformMT"], 10000)

plt.scatter(x,y)
plt.show()
