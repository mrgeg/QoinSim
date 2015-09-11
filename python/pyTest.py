import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import PyQoinSim
import csv

def get_mc_laplace_transform(rdm_var, lam):
	f = map(lambda v: np.exp(-v * lam), rdm_var)	
	return np.mean(f)

random 	= PyQoinSim.RandomVarInt()

# x = random.getRandom(["TYPE:UniformMT"], 100)
# y = random.getRandom(["TYPE:UniformMT"], 100)

# fig = plt.figure()
# axe = fig.add_subplot(111);

# axe.scatter(x,y, s=10, c='b', marker="s", label='Mersenne Twister')

# plt.legend(loc='upper left');
# plt.show()

poi = random.getRandom(["TYPE:Poisson"], 200000)
exp = random.getRandom(["TYPE:Exponential"], 200000)
normINV = random.getRandom(["TYPE:NormalCNINV"], 200000) 
normBOX = random.getRandom(["TYPE:NormalBox"], 200000)

print("MC Mean: %s, TH Mean: %s" % (np.mean(exp), 1./0.5))
print("MC Mean: %s, TH Mean: %s" % (np.mean(normINV), 0.))
print("MC Mean: %s, TH Mean: %s" % (np.mean(normBOX), 0.))


lam = np.linspace(0,2,100)

mc_poi = map(lambda x: get_mc_laplace_transform(poi, x), lam)
th_poi = map (lambda x: np.exp(2.*(np.exp(-x)-1)), lam)

plt.plot(lam, mc_poi, c='r')
plt.plot(lam, th_poi, c='b')
plt.legend(['MC Poisson Laplace Transform', 'TH Poisson Laplace Transform'], loc='upper left')
plt.grid()
plt.show()

lam = np.linspace(0,2.,100)

mc_exp = map(lambda x: get_mc_laplace_transform(exp, x), lam)
th_exp = map (lambda x: 0.5 / (0.5 + x), lam)

plt.plot(lam, mc_exp, c='r')
plt.plot(lam, th_exp, c='b')
plt.legend(['MC Exponential Laplace Transform', 'TH Exponential Laplace Transform'], loc='upper left')
plt.grid()
plt.show()

lam = np.linspace(-1,1,100)

mc_normINV = map(lambda x: get_mc_laplace_transform(normINV, x), lam)
mc_normBOX = map(lambda x: get_mc_laplace_transform(normBOX, x), lam)
th_norm = map(lambda x: np.exp(x*x/2.), lam)

plt.plot(lam, mc_normINV, c='r')
plt.plot(lam, mc_normBOX, c='b')
plt.plot(lam, th_norm, c='g')
plt.grid()
plt.legend(['MC NormInv Laplace Transform','MC NormBox Laplace Transform','TH Normal Laplace Transform'], loc='upper left')
plt.show()

# plt.scatter(px, py)
# plt.show()

# gx = random.getRandom(["TYPE:NormalCNINV"], 15000)
# gy = random.getRandom(["TYPE:NormalCNINV"], 15000)

# g1x = random.getRandom(["TYPE:NormalBox"], 15000)
# g1y = random.getRandom(["TYPE:NormalBox"], 15000)

# fig = plt.figure()
# axe = fig.add_subplot(111);

# axe.scatter(gx,gy, s=10, c='b', marker="s", label='Normal CNInv')
# axe.scatter(g1x,g1y, s=10, c='r', marker="o", label='Normal Box')

# plt.legend(loc='upper left');
# plt.show()



# x = random.getRandom(["TYPE:UniformMT"], 1100)
# y = random.getRandom(["TYPE:UniformMT"], 1100)

# x1 = random.getRandom(["TYPE:UniformSobol","SOBOLDIM:1100"], 1100)
# y1 = random.getRandom(["TYPE:UniformSobol","SOBOLDIM:1100"], 1100)

# fig = plt.figure()
# axe = fig.add_subplot(111);

# axe.scatter(x,y, s=10, c='b', marker="s", label='Mersenne Twister')
# axe.scatter(x1,y1, s=10, c='r', marker="o", label='Sobol1111')

# plt.legend(loc='upper left');
# plt.show()



