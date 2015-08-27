#ifndef POISSONPROCESS_H
#define POISSONPROCESS_H

#include <RandomProcess.h>
#include "RandomExpo.h"
#include "RandomVarEnv.h"

namespace QOINSIM {

class PoissonProcess : public RandomProcess {
public:
  PoissonProcess(double p_lambda);

  virtual ~PoissonProcess();

public:
  matrix<double> generatePaths(int p_pathsNumber, const std::vector<double>& p_disc);

  matrix<double> generatePaths(double p_timeMax, int p_discNumber, int p_pathsNumber);

private:
  double                        m_lambda;
  std::shared_ptr<RandomExpo>   m_pExpo;
};
}
#endif // POISSONPROCESS_H
