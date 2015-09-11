#include "EulerDiscretization.h"
#include "boost/numeric/ublas/operation.hpp"

namespace QOINSIM {

EulerDiscretization::EulerDiscretization(const std::shared_ptr<RandomNormal>& p_pNorm)
: m_pNorm(p_pNorm)
{
}

vector<double>
EulerDiscretization::bvCast(const std::vector<double>& p_vect) const {
  vector<double> l_res(p_vect.size());

  for (int l_i = 0; l_i < p_vect.size(); l_i++)
    l_res[l_i] = p_vect[l_i];

  return l_res;
}

matrix<double>
EulerDiscretization::generatePath(EEulerDiscType p_type, double p_timeMax, int p_discNum,
  const std::shared_ptr<ItoDiffusion>& p_pIto){

  switch(p_type){
    default:
    case EEulerDiscType::E_Discrete:
      return generateDiscrete(p_timeMax, p_discNum, p_pIto);
    case EEulerDiscType::E_Continuous:
      return generateContinuous(p_timeMax, p_discNum, p_pIto);
  }
}

matrix<double>
EulerDiscretization::generateDiscrete(double p_timeMax, int p_discNum,
  const std::shared_ptr<ItoDiffusion>& p_pIto){

  matrix<double> l_res(p_pIto->dimension(), p_discNum + 1);
  vector<double> l_clmn  = p_pIto->init();
  double         l_dt    = p_timeMax / (double)p_discNum;
  double         l_t     = 0.;

  for (int l_j = 0; l_j < p_discNum; l_j++){
    column(l_res, l_j) = l_clmn;

    l_clmn = l_clmn + l_dt * p_pIto->mu(l_t, l_clmn)
      + std::sqrt(l_dt) * prod(p_pIto->sigma(l_t, l_clmn), bvCast(m_pNorm->gen(p_pIto->dimension())));

    l_t += l_dt;
  }

  return l_res;
}

matrix<double>
EulerDiscretization::generateContinuous(double p_timeMax, int p_discNum,
  const std::shared_ptr<ItoDiffusion>& p_pIto){
  matrix<double> l_res;

  return l_res;
}

}

