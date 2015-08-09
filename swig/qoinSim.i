%module qoinSim
%{
#include "headerForSwig.h"
%}

class RandomVarInt{
  public:
    RandomVarInt();
    ~RandomVarInt();

  public:
    double getRandom(char* p_type);
    double* getRandom(char* p_type, unsigned int p_size);
};
