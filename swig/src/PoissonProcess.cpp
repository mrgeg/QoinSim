#include "PoissonProcess.h"

namespace QOINSIM {

PoissonProcess::PoissonProcess(const std::shared_ptr<RandomUniform>& p_unif, double p_lambda) :
  m_lambda(p_lambda), m_pPoisson(new RandomPoisson(p_unif, p_lambda))
  {}

matrix<double>
PoissonProcess::generatePaths(int p_pathsNumber, const std::vector<double>& p_disc){
  matrix<double>  l_res(p_pathsNumber + 1, p_disc.size() + 1);

  l_res(0, 0) = .0;

  for (int l_i = 1; l_i < l_res.size2(); l_i++){
    l_res(0, l_i) = l_res(0, l_i-1) + p_disc[l_i-1];
  }

  for (int l_row = 1; l_row <= p_pathsNumber; l_row++){
    l_res(l_row, 0) = 0;
    for (int l_i = 0; l_i < p_disc.size(); l_i++){

      m_pPoisson->set(m_lambda * p_disc[l_i]);
      l_res(l_row, l_i+1) = l_res(l_row, l_i) + m_pPoisson->gen();
    }
  }

  return l_res;
}

matrix<double>
PoissonProcess::generatePaths(double p_timeMax, int p_discNumber, int p_pathsNumber){
  matrix<double>  l_res(p_pathsNumber + 1, p_discNumber + 1);
  double          l_dt = p_timeMax / (double)p_discNumber;

  l_res(0, 0) = .0;

  for (int l_i = 1; l_i < l_res.size2(); l_i++){
    l_res(0, l_i) = l_res(0, l_i-1) + l_dt;
  }

  m_pPoisson->set(m_lambda * l_dt);

  for (int l_row = 1; l_row <= p_pathsNumber; l_row++){
    l_res(l_row, 0) = 0.;
    for (int l_clmn = 0; l_clmn < p_discNumber; l_clmn++)
      l_res(l_row, l_clmn+1) = l_res(l_row, l_clmn) + m_pPoisson->gen();
  }

  return l_res;
}
}
