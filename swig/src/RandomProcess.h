#ifndef RANDOMPROCESS_H
#define RANDOMPROCESS_H

#include "Misc.h"
#include "boost/numeric/ublas/matrix.hpp"

using namespace boost::numeric::ublas;

namespace QOINSIM {

class RandomProcess {
public:
  enum EProcessType {
    E_Poisson = 0,
    E_Hawkes
  };
public:
  virtual ~RandomProcess(){}

public:
  virtual matrix<double> generatePaths(int p_pathsNumber, const std::vector<double>& p_disc)  = 0;

  virtual matrix<double> generatePaths(double p_timeMax, int p_discNumber, int p_pathsNumber) = 0;

public:
  static const std::map<std::string, EProcessType> s_typeMap;
};
}

#endif // RANDOMPROCESS_H
