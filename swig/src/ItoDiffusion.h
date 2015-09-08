#ifndef ITODIFFUSION_H
#define ITODIFFUSION_H

#include "Misc.h"
#include "boost/numeric/ublas/matrix.hpp"
#include "boost/numeric/ublas/vector.hpp"

using namespace boost::numeric::ublas;

namespace QOINSIM {

class ItoDiffusion {
public:
  ItoDiffusion(int p_brwnN = 1, int p_dim = 1) : m_brwnN(p_brwnN), m_dim(p_dim)
  {}

  virtual ~ItoDiffusion(){}

public:
  virtual vector<double> init();
  virtual vector<double> mu(double p_time, const vector<double>& p_x)     = 0;
  virtual matrix<double>      sigma(double p_time, const vector<double>& p_x)  = 0;

public:
  int brwnN()     const {return m_brwnN;}
  int dimension() const {return m_dim;}

protected:
  int m_brwnN;
  int m_dim;
};
}

#endif // ITODIFFUSION_H
