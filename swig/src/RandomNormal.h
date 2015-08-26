#ifndef RANDOMNORMAL_H
#define RANDOMNORMAL_H

#include <Random.h>

namespace QOINSIM {

class RandomNormal : public Random {
public:
  RandomNormal(const std::shared_ptr<RandomUniform>& p_pUniform,
    double p_mu = 0, double p_sig = 1);

  virtual ~RandomNormal(){}

public:
  virtual void                reset();
  virtual double              gen()                     = 0;
  virtual std::vector<double> gen(unsigned int p_size)  = 0;

protected:
  std::shared_ptr<RandomUniform>  m_pUniform;
  double                          m_mu;
  double                          m_sig;
};
}

#endif // RANDOMNORMAL_H
