import matplotlib.pyplot as plt
import PyQoinSim

random 	= PyQoinSim.RandomVarInt()

args = PyQoinSim.VectorString()

args.append("TYPE:UniformMT")


x = random.getRandom(args, 10000)
y = random.getRandom(args, 10000)

plt.scatter(x,y)
plt.show()
