#ifndef RANDOM_H
#define RANDOM_H

#include "Misc.h"

namespace QOINSIM {

class Random{
  public:
    enum ERandomVarType{
      E_UniformMT = 0,
      E_UniformSobol366,
      E_UniformSobol1111,
      E_MAX
};
  public:
    virtual ~Random(){}

  public:
    virtual void                reset()         = 0;
    virtual double              gen()           = 0;
    virtual std::vector<double> gen(unsigned int p_size) = 0;
};

class RandomUniform : public Random{
  public:
    virtual ~RandomUniform(){}

    virtual void                reset()                  = 0;
    virtual double              gen()                    = 0;
    virtual std::vector<double> gen(unsigned int p_size) = 0;
};
}

#endif // RANDOM_H
