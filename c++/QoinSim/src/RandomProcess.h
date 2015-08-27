#ifndef RANDOMPROCESS_H
#define RANDOMPROCESS_H

#include "Misc.h"
#include "Random.h"
#include "boost/numeric/ublas/matrix.hpp"

using namespace boost::numeric::ublas;

namespace QOINSIM {

class RandomProcess {
public:
  enum EProcessType {
    E_Poisson = 0
  };
public:
  RandomProcess(const std::shared_ptr<RandomUniform>& p_unif) :
  m_unif(p_unif)
  {}

  virtual ~RandomProcess(){}

public:
  virtual matrix<double> generatePaths(int p_pathsNumber, const std::vector<double>& p_disc)  = 0;

  virtual matrix<double> generatePaths(double p_timeMax, int p_discNumber, int p_pathsNumber) = 0;

public:
  static const std::map<std::string, EProcessType> s_typeMap;

protected:
  std::shared_ptr<RandomUniform> m_unif;
};
}

#endif // RANDOMPROCESS_H
