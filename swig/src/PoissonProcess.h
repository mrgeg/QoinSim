#ifndef POISSONPROCESS_H
#define POISSONPROCESS_H

#include <RandomProcess.h>
#include "RandomPoisson.h"
#include "RandomVarEnv.h"

namespace QOINSIM {

class PoissonProcess : public RandomProcess {
public:
  PoissonProcess(const std::shared_ptr<RandomUniform>& p_unif, double p_lambda);

  virtual ~PoissonProcess(){}

public:
  virtual matrix<double> generatePaths(int p_pathsNumber, const std::vector<double>& p_disc);

  virtual matrix<double> generatePaths(double p_timeMax, int p_discNumber, int p_pathsNumber);

protected:
  std::shared_ptr<RandomPoisson>  m_pPoisson;

private:
  double                          m_lambda;
};
}
#endif // POISSONPROCESS_H
