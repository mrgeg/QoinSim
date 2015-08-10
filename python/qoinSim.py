import ctypes
import os

path = os.getcwd() + '/qoinSim_wrap.so'

qoinSimLib = ctypes.cdll.LoadLibrary(path)
randomInt  = qoinSimLib.new_RandomVarInt()

print randomInt.getRandom("UniformMT")