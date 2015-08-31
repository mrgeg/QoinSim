#include "RandomPoisson.h"

namespace QOINSIM {


RandomPoisson::RandomPoisson(const std::shared_ptr<RandomUniform>& p_pUniform,
  double p_lambda) : m_lambda(p_lambda)
{
  m_pUniform = p_pUniform;
}

//Pages p.22
double
RandomPoisson::gen(){
  double  l_unifProd = std::log(m_pUniform->gen());
  int     l_n = 0;

  while(l_unifProd >= -m_lambda){
    l_unifProd += std::log(m_pUniform->gen());
    ++l_n;
  }

  return (double)l_n;
}

std::vector<double>
RandomPoisson::gen(unsigned int p_size){
  std::vector<double> l_res(p_size);

  for (unsigned int l_i = 0; l_i < p_size; l_i++){
    l_res.push_back(gen());
  }

  return l_res;
}

void
RandomPoisson::reset(){
  m_pUniform->reset();
}
}
