import matplotlib.pyplot as plt
import PyQoinSim

random 	= PyQoinSim.RandomVarInt()

px = random.getRandom(["TYPE:Poisson"], 1000)
py = random.getRandom(["TYPE:Exponential"], 1000)

plt.scatter(px, py)
plt.show()

gx = random.getRandom(["TYPE:NormalCNINV"], 15000)
gy = random.getRandom(["TYPE:NormalCNINV"], 15000)

g1x = random.getRandom(["TYPE:NormalBox"], 15000)
g1y = random.getRandom(["TYPE:NormalBox"], 15000)

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
