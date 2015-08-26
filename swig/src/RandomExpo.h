#ifndef RANDOMEXPO_H
#define RANDOMEXPO_H

#include <Random.h>
#include "Misc.h"

namespace QOINSIM {

class RandomExpo : public Random
{
public:
  RandomExpo(const std::shared_ptr<RandomUniform>& p_pUniform, double p_lambda);
  virtual ~RandomExpo(){}

public:
  double              gen();
  std::vector<double> gen(unsigned int p_size);
  void                reset();

private:
  double                          m_lambda;
  std::shared_ptr<RandomUniform>  m_pUniform;
};
}
#endif // RANDOMEXPO_H
