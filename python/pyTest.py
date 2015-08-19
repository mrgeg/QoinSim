import matplotlib.pyplot as plt
import PyQoinSim

random = PyQoinSim.RandomVarInt()

x = random.getRandom("UniformMT", 10000)
y = random.getRandom("UniformMT", 10000)

plt.scatter(x,y)
plt.show()
