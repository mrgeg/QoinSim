#ifndef RANDOMPOISSON_H
#define RANDOMPOISSON_H

#include <RandomNormal.h>
#include "Misc.h"

namespace QOINSIM {

class RandomPoisson : public Random
{
public:
  RandomPoisson(const std::shared_ptr<RandomUniform>& p_pUniform, double p_lambda);
  virtual ~RandomExpo(){}

public:
  double              gen();
  std::vector<double> gen(unsigned int p_size);
  void                reset();

public:
  void set(double p_lambda) {m_lambda = p_lambda;}

private:
  Erf                             m_erf;
  double                          m_lambda;
  std::shared_ptr<RandomUniform>  m_pUniform;
};
}
#endif // RANDOMPOISSON_H
