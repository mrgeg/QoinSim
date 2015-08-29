#ifndef HAWKESPROCESS_H
#define HAWKESPROCESS_H

#include <RandomProcess.h>
#include "Random.h"

namespace QOINSIM {

class HawkesProcess : public RandomProcess {
public:
  HawkesProcess(const std::shared_ptr<RandomUniform>& p_unif,
  double p_mu, double p_alpha, double p_beta);

  virtual ~PoissonProcess(){}

public:
  matrix<double> generatePaths(int p_pathsNumber, const std::vector<double>& p_disc);

  matrix<double> generatePaths(double p_timeMax, int p_discNumber, int p_pathsNumber);

private:
  double                        m_mu;
  double                        m_alpha;
  double                        m_beta;
  std::shared_ptr<RandomExpo>   m_pExpo;
};
}

#endif // HAWKESPROCESS_H
