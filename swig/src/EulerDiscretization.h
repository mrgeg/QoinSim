#ifndef EULERDISCRETIZATION_H
#define EULERDISCRETIZATION_H

#include "RandomNormal.h"
#include "ItoDiffusion.h"
#include "boost/numeric/ublas/matrix.hpp"
#include "boost/numeric/ublas/vector.hpp"


using namespace boost::numeric::ublas;

namespace QOINSIM {

class EulerDiscretization
{
public:
  enum EEulerDiscType {
  E_Discrete   = 0,
  E_Continuous
  };

public:
  EulerDiscretization(const std::shared_ptr<RandomNormal>& p_pNorm);
  virtual ~EulerDiscretization(){}

public:
  matrix<double> generatePath(EEulerDiscType p_type, double p_timeMax, int p_discNum, const std::shared_ptr<ItoDiffusion>& p_pIto);

private:
  vector<double> bvCast(const std::vector<double>& p_vect) const;
  matrix<double> generateDiscrete(double p_timeMax, int p_discNum, const std::shared_ptr<ItoDiffusion>& p_pIto);
  matrix<double> generateContinuous(double p_timeMax, int p_discNum, const std::shared_ptr<ItoDiffusion>& p_pIto);

private:
  std::shared_ptr<RandomNormal> m_pNorm;
};
}

#endif // EULERDISCRETIZATION_H
