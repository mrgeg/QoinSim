#include "PoissonProcess.h"

namespace QOINSIM {

PoissonProcess::PoissonProcess(const std::shared_ptr<RandomUniform>& p_unif, double p_lambda) :
  m_lambda(p_lambda), m_pExpo(new RandomExpo(p_unif, p_lambda))
  {}

matrix<double>
PoissonProcess::generatePaths(int p_pathsNumber, const std::vector<double>& p_disc){
  matrix<double>  l_res(p_pathsNumber, p_disc.size());
  double          l_dt = 0.;

  for (int l_row = 0; l_row < p_pathsNumber; l_row++){
    l_res(l_row, 0);
    for (int l_clmn = 0; l_clmn < p_disc.size()-1; l_clmn++){
      l_dt = p_disc[l_clmn+1]-p_disc[l_clmn];

      m_pExpo->set(m_lambda * l_dt);
      l_res(l_row, l_clmn+1) = l_res(l_row, l_clmn) + m_pExpo->gen();
    }
  }

  return l_res;
}

matrix<double>
PoissonProcess::generatePaths(double p_timeMax, int p_discNumber, int p_pathsNumber){
  matrix<double>  l_res(p_pathsNumber, p_discNumber);
  double          l_dt = p_timeMax / (double)p_discNumber;

  m_pExpo->set(m_lambda * l_dt);

  for (int l_row = 0; l_row < p_pathsNumber; l_row++){
    l_res(l_row, 0);
    for (int l_clmn = 0; l_clmn < p_discNumber-1; l_clmn++)
      l_res(l_row, l_clmn+1) = l_res(l_row, l_clmn) + m_pExpo->gen();
  }

  return l_res;
}
}
