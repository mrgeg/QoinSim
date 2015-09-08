#ifndef RANDOMNORMALCNINV_H
#define RANDOMNORMALCNINV_H

#include <RandomNormal.h>
#include "Misc.h"

namespace QOINSIM {

class RandomNormalCNINV : public RandomNormal {
public:
  RandomNormalCNINV(const std::shared_ptr<RandomUniform>&  p_pUniform,
    double p_mu = 0., double p_sig = 1.);

  virtual ~RandomNormalCNINV(){}

public:
  double              gen();
  std::vector<double> gen(unsigned int p_size);

private:
  Erf m_erf;
};
}

#endif // RANDOMNORMALCNINV_H
