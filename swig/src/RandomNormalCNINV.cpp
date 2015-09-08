#include "RandomNormalCNINV.h"

namespace QOINSIM {

const double Erf::s_cof[28] = {
-1.3026537197817094,6.4196979235649026e-1,1.9476473204185836e-2,-9.561514786808631e-3,
-9.46595344482036e-4,3.66839497852761e-4,4.2523324806907e-5,-2.0278578112534e-5,
-1.624290004647e-6,1.303655835580e-6,1.5626441722e-8,-8.5238095915e-8,6.529054439e-9,
5.059343495e-9,-9.91364156e-10,-2.27365122e-10,9.6467911e-11,2.394038e-12,-6.886027e-12,
8.94487e-13,3.13092e-13,-1.12708e-13,3.81e-16,7.106e-15,-1.523e-15,-9.4e-17,1.21e-16,-2.8e-17};

RandomNormalCNINV::RandomNormalCNINV(const std::shared_ptr<RandomUniform>& p_pUniform,
  double p_mu, double p_sig)
: RandomNormal(p_pUniform, p_mu, p_sig)
{}

double
RandomNormalCNINV::gen(){
  double l_unif = m_pUniform->gen();

  return -1.41421356237309505 * m_sig * m_erf.inverfc(2. * l_unif) + m_mu;
}

std::vector<double>
RandomNormalCNINV::gen(unsigned int p_size){
  std::vector<double> l_res(p_size);

  for (unsigned int l_i = 0; l_i < p_size; l_i++){
    l_res.push_back(gen());
  }

  return l_res;
}

}
