#include "OrnUhlenProcess.h"

namespace QOINSIM {

OrnUhlenProcess::OrnUhlenProcess(const std::shared_ptr<RandomNormal>& p_pNorm,
    double p_x0, double p_xinf, double p_slope, double p_sigma)
      : m_euler(p_pNorm), m_diff(new OrnUhlenDiffusion(p_x0, p_xinf, p_slope, p_sigma))
{}

vector<double>
OrnUhlenProcess::OrnUhlenDiffusion::init(){
  vector<double> l_res(1); l_res[0] = m_x0;

  return l_res;
}

vector<double>
OrnUhlenProcess::OrnUhlenDiffusion::mu(double p_time, const vector<double>& p_x){
  vector<double> l_res(1); l_res[0] = m_xinf - m_slope * p_x[0];

  return l_res;
}

matrix<double>
OrnUhlenProcess::OrnUhlenDiffusion::sigma(double p_time, const vector<double>& p_x){
  matrix<double> l_res(1, 1); l_res(0, 0) = m_sigma;

  return l_res;
}

matrix<double>
OrnUhlenProcess::generatePaths(int p_pathsNumber, const std::vector<double>& p_disc){
  matrix<double> l_res;

  return l_res;
}

matrix<double>
OrnUhlenProcess::generatePaths(double p_timeMax, int p_discNumber, int p_pathsNumber){
  matrix<double>  l_path;
  matrix<double>  l_res(p_pathsNumber + 1, p_discNumber + 1);
  double          l_dt = p_timeMax / (double)p_discNumber;

  l_res(0, 0) = .0;

  for (int l_i = 1; l_i < l_res.size2(); l_i++){
    l_res(0, l_i) = l_res(0, l_i-1) + l_dt;
  }

  for (int l_row = 1; l_row <= p_pathsNumber; l_row++){
    l_path = m_euler.generatePath(EulerDiscretization::E_Discrete, p_timeMax, p_discNumber + 1, m_diff);
    for (int l_j = 0; l_j < l_res.size2(); l_j++){
      l_res(l_row, l_j) = l_path(0, l_j);
    }
  }

  return l_res;
}
}
