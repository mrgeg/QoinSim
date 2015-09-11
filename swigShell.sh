currentPath=$(pwd)
buildType=$1

echo "Starting to $buildType-build QoinSim c++/python wrapper..."

cp -fr $currentPath/c++/QoinSim/src/* $currentPath/swig/src/

swig -c++ -python -o $currentPath/swig/src/qoinSim_wrap.cpp $currentPath/swig/qoinSim.i

if [ "$buildType" == "Debug" ]; then
g++ -g -fPIC -c $currentPath/swig/src/qoinSim_wrap.cpp -o $currentPath/swig/obj/$buildType/qoinSim_wrap.o -I/usr/include/python2.7/
else
g++ -fPIC -c $currentPath/swig/src/qoinSim_wrap.cpp -o $currentPath/swig/obj/$buildType/qoinSim_wrap.o -I/usr/include/python2.7/
fi

cp -fr $currentPath/c++/QoinSim/obj/$buildType/src/* $currentPath/swig/obj/$buildType/
cd $currentPath/swig/obj/$buildType/

if [ "$buildType" == "Debug" ]; then
g++ -g -shared qoinSim_wrap.o Misc.o Random.o RandomUniformMT.o RandomUniformSobol.o RandomNormal.o RandomNormalCNINV.o RandomExpo.o RandomNormalBox.o RandomPoisson.o RandomProcess.o PoissonProcess.o HawkesProcess.o EulerDiscretization.o ItoDiffusion.o OrnUhlenProcess.o RandomVarEnv.o RandomVarInt.o -o $currentPath/swig/bin/$buildType/_PyQoinSim.so
else
g++ -shared qoinSim_wrap.o Misc.o Random.o RandomUniformMT.o RandomUniformSobol.o RandomNormal.o RandomNormalCNINV.o RandomExpo.o RandomNormalBox.o RandomPoisson.o RandomProcess.o PoissonProcess.o HawkesProcess.o EulerDiscretization.o ItoDiffusion.o OrnUhlenProcess.o RandomVarEnv.o RandomVarInt.o -o $currentPath/swig/bin/$buildType/_PyQoinSim.so
fi

cp -fr $currentPath/swig/bin/$buildType/_PyQoinSim.so $currentPath/python/
cp -fr $currentPath/swig/src/PyQoinSim.py $currentPath/python/
