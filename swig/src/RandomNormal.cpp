#include "RandomNormal.h"

namespace QOINSIM {

RandomNormal::RandomNormal(const std::shared_ptr<RandomUniform>&  p_pUniform,
  double p_mu, double p_sig) :
m_mu(p_mu), m_sig(p_sig)
{
  m_pUniform = p_pUniform;
}

void
RandomNormal::reset(){
  m_pUniform->reset();
}
}
