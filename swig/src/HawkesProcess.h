#ifndef HAWKESPROCESS_H
#define HAWKESPROCESS_H

#include <RandomProcess.h>
#include "PoissonProcess.h"


namespace QOINSIM {

class HawkesProcess : public PoissonProcess {
public:
  HawkesProcess(const std::shared_ptr<RandomUniform>& p_unif,
  double p_mu, double p_alpha, double p_beta);

  virtual ~HawkesProcess(){}

public:
  matrix<double> generatePaths(int p_pathsNumber, const std::vector<double>& p_disc);

  matrix<double> generatePaths(double p_timeMax, int p_discNumber, int p_pathsNumber);

private:
  double simArrivalIntervalTime(double p_lambda);
  double phi(double p_time);
  double generateState(double& r_time, double& p_n1, double& p_n2, double& p_lambda1, double& p_lambda2);
  void   generateOnePath(long p_row, double p_timeMax, std::vector<double> p_dizcs, matrix<double>& r_paths);

private:
  double                          m_mu;
  double                          m_alpha;
  double                          m_beta;
  std::shared_ptr<RandomUniform>  m_pUnif;
};
}

#endif // HAWKESPROCESS_H
