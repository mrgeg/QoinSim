#include "RandomNormalBox.h"

namespace QOINSIM {

RandomNormalBox::RandomNormalBox(const std::shared_ptr<RandomUniform>& p_pUniform,
  double p_mu, double p_sig)
: RandomNormal(p_pUniform, p_mu, p_sig), m_flag(true), m_r2(0.), m_theta(0.)
{
  m_pExpo = std::make_shared<RandomExpo>(p_pUniform, 0.5);
}

double
RandomNormalBox::gen(){
  m_flag = !m_flag;

  if (!m_flag){
    m_theta = 2.0 * M_PI * m_pUniform->gen();
    m_r2    = m_pExpo->gen();

    return std::sqrt(m_r2) * std::cos(m_theta);
  }
  else
    return std::sqrt(m_r2) * std::sin(m_theta);
}

std::vector<double>
RandomNormalBox::gen(unsigned int p_size){
  std::vector<double> l_res(p_size);

  for (unsigned int l_i = 0; l_i < p_size; l_i++){
    l_res[l_i] = gen();
  }

  return l_res;
}

void
RandomNormalBox::reset(){
  RandomNormal::reset();
  m_pExpo->reset();

  m_flag  = true;
  m_r2    = 0.;
  m_theta = 0.;
}

}
