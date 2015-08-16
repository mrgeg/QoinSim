%module PyQoinSim
%{
#include "RandomVarInt.h"
%}

namespace QOINSIM {
class RandomVarInt{
  public:
    RandomVarInt();
    ~RandomVarInt();

  public:
    double getRandom(char* p_type);
    double* getRandomVect(char* p_type, unsigned int p_size);
};
}
