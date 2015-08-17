from pylab import *
import PyQoinSim

random = PyQoinSim.RandomVarInt()

x = random.getRandom("UniformMT", 10000)
y = random.getRandom("UniformMT", 10000)

plot(x,y)
show()
