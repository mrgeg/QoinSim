import matplotlib.pyplot as plt
import PyQoinSim

random 	= PyQoinSim.RandomVarInt()

gx = random.getRandom(["TYPE:NormalCNINV"], 10000)
gy = random.getRandom(["TYPE:NormalCNINV"], 10000)

g1x = random.getRandom(["TYPE:NormalBox"], 10000)
g1y = random.getRandom(["TYPE:NormalBox"], 10000)

fig = plt.figure()
axe = fig.add_subplot(111);

axe.scatter(gx,gy, s=10, c='b', marker="s", label='Normal CNInv')
axe.scatter(g1x,g1y, s=10, c='r', marker="o", label='Normal Box')

plt.legend(loc='upper left');
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
