#include "RandomExpo.h"

namespace QOINSIM {


RandomExpo::RandomExpo(const std::shared_ptr<RandomUniform>& p_pUniform,
  double p_lambda) : m_lambda(p_lambda)
{
  m_pUniform = p_pUniform;
}

double
RandomExpo::gen(){
  double l_unif = m_pUniform->gen();

  return - std::log(l_unif) / m_lambda;
}

std::vector<double>
RandomExpo::gen(unsigned int p_size){
  std::vector<double> l_res(p_size);

  for (unsigned int l_i = 0; l_i < p_size; l_i++){
    l_res[l_i] = gen();
  }

  return l_res;
}

void
RandomExpo::reset(){
  m_pUniform->reset();
}
}
