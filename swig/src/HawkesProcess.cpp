#include "HawkesProcess.h"

typedef std::tuple<double,double,double,double> quadruple;

namespace QOINSIM {

HawkesProcess::HawkesProcess(const std::shared_ptr<RandomUniform>& p_unif,
  double p_mu, double p_alpha, double p_beta) :
  PoissonProcess(p_unif, 0.), m_pUnif(p_unif), m_mu(p_mu), m_alpha(p_alpha), m_beta(p_beta)
{}

matrix<double>
HawkesProcess::generatePaths(int p_pathsNumber, const std::vector<double>& p_disc){
  matrix<double> l_res(p_pathsNumber + 1, p_disc.size()+1);

  double l_timeMax = .0;
  l_res(0, 0) = .0;

  for (int l_i = 1; l_i < l_res.size2(); l_i++){
    l_timeMax += p_disc[l_i-1];
    l_res(0, l_i) = l_timeMax;
  }

  for (int l_i = 1; l_i < l_res.size1(); l_i++)
    generateOnePath(l_i, l_timeMax, p_disc, l_res);

  return l_res;
}

matrix<double>
HawkesProcess::generatePaths(double p_timeMax, int p_discNumber, int p_pathsNumber){
  std::vector<double> l_dizcs (p_discNumber);

  double l_dizc = p_timeMax / (double) p_discNumber;

  for (int l_i = 0; l_i < p_discNumber; l_i++)
      l_dizcs[l_i] = l_dizc;

  return generatePaths(p_pathsNumber, l_dizcs);
}

void
HawkesProcess::generateOnePath(long p_row, double p_timeMax, std::vector<double> p_dizcs, matrix<double>& r_paths) {
double l_lambda1 = 2.0 * m_mu; double l_lambda2 = 2.0 * m_mu;
  double l_n1      = .0;         double l_n2      = .0;

  double l_time     = .0;

  std::map<double, quadruple> l_map;

  while (l_time < p_timeMax) {
    generateState(l_time, l_n1, l_n2, l_lambda1, l_lambda2);
    l_map[l_time] = std::make_tuple(l_n1, l_n2, l_lambda1, l_lambda2);
  }

  std::map<double, quadruple>::iterator l_it = l_map.begin();
  l_time = .0;

  for (int l_i = 0; l_i < p_dizcs.size(); l_i++){
    l_time += p_dizcs[l_i];

    while (l_it->first < l_time && l_it != l_map.end())
      l_it++;

    r_paths(p_row, l_i) = std::get<1>(l_it->second) - std::get<0>(l_it->second);
  }
}

double
HawkesProcess::simArrivalIntervalTime(double p_lambda) {
  double l_d = 1 + m_beta * std::log(m_pUnif->gen()) / (p_lambda - m_mu);

  double l_s2 = - std::log(m_pUnif->gen()) / m_mu;

  if (l_d < 0)
    return l_s2;

  double l_s1 = - log(l_d) / m_beta;

  return l_d > 0 ? std::min(l_s1, l_s2) : l_s2;
}

double
HawkesProcess::generateState(double& r_time, double& r_n1, double& r_n2,
 double& r_lambda1, double& r_lambda2){
  double l_arrivalIntTime = simArrivalIntervalTime(r_lambda1);
  double l_tmp            = simArrivalIntervalTime(r_lambda2);

  if (l_arrivalIntTime > l_tmp){
    l_arrivalIntTime = l_tmp;
    ++r_n2;
  }
  else ++r_n1;

  r_time += l_arrivalIntTime;


  double l_lambda1 = (r_lambda1 - m_mu) * std::exp(-m_beta * l_arrivalIntTime) + m_mu;
  double l_lambda2 = (r_lambda2 - m_mu) * std::exp(-m_beta * l_arrivalIntTime) + m_mu;

  m_pPoisson->set(l_lambda2 * l_arrivalIntTime);
  r_lambda1 = l_lambda1 + m_alpha * m_pPoisson->gen();

  m_pPoisson->set(l_lambda1 * l_arrivalIntTime);
  r_lambda2 = l_lambda2 + m_alpha * m_pPoisson->gen();
 }

}
