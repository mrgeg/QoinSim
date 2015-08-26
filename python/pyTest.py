import matplotlib.pyplot as plt
import PyQoinSim

random 	= PyQoinSim.RandomVarInt()

g1 = random.getRandom(["TYPE:NormalCNINV"], 10000)
g2 = random.getRandom(["TYPE:NormalCNINV"], 10000)


plt.scatter(g1,g2)
plt.show()

x = random.getRandom(["TYPE:UniformMT"], 1100)
y = random.getRandom(["TYPE:UniformMT"], 1100)

x1 = random.getRandom(["TYPE:UniformSobol","SOBOLDIM:1100"], 1100)
y1 = random.getRandom(["TYPE:UniformSobol","SOBOLDIM:1100"], 1100)

fig = plt.figure()
axe = fig.add_subplot(111);

axe.scatter(x,y, s=10, c='b', marker="s", label='Mersenne Twister')
axe.scatter(x1,y1, s=10, c='r', marker="o", label='Sobol1111')

plt.legend(loc='upper left');
plt.show()
