#ifndef RANDOMNORMAL_H
#define RANDOMNORMAL_H

#include <Random.h>

namespace QOINSIM {

//from numerical recipes p.264
struct Erf {
  static const int    s_ncof=28;
  static const double s_cof[28];

  inline double erf(double p_x){
    if (p_x >= 0.) return 1.0 - erfccheb(p_x);
    else return erfccheb(-p_x)-1.0;
  }

  inline double erfc(double p_x){
    if (p_x >= 0.) return erfccheb(p_x);
    else return 2.0 - erfccheb(-p_x);
  }

  double erfccheb(double p_z){
    int l_j;
    double l_t, l_ty, l_tmp, l_d = 0., l_dd = 0.;
    if (p_z < 0.) throw "erfccheb requires nonnegative argument";

    l_t   = 2./(2. + p_z);
    l_ty  = 4. * l_t - 2.;
    for (l_j = s_ncof - 1; l_j > 0; l_j--){
      l_tmp = l_d;
      l_d   = l_ty * l_d - l_dd + s_cof[l_j];
      l_dd  = l_tmp;
    }

    return l_t * std::exp(-p_z * p_z + 0.5 * (s_cof[0] + l_ty * l_d) - l_dd);
  }

  double inverfc(double p_p){
    double l_x, l_err, l_t, l_pp;
    if (p_p >= 2.) return -100.;
    if (p_p <= 0.) return +100.;

    l_pp = (p_p < 1.0)? p_p : 2. - p_p;
    l_t  = std::sqrt(-2. * std::log(l_pp / 2.));
    l_x  = -0.70711*((2.30753+l_t*0.27061)/(1.+l_t*(0.99229+l_t*0.04481)) - l_t);

    for (int l_i = 0; l_i < 2; l_i++){
      l_err = erfc(l_x) - l_pp;
      l_x   += l_err / (1.12837916709551257*std::exp(-l_x * l_x)-l_x * l_err);
    }

    return (p_p < 1.? l_x : -l_x);
  }

  inline double inverf(double p_p){
    return inverfc(1. - p_p);
  }

  inline double quant(double p_p){
    return std::sqrt(2.) * inverf(2.*p_p-1);
  }
};

class RandomNormal : public Random {
public:
  RandomNormal(const std::shared_ptr<RandomUniform>& p_pUniform,
    double p_mu = 0, double p_sig = 1);

  virtual ~RandomNormal(){}

public:
  virtual void                reset();
  virtual double              gen()                     = 0;
  virtual std::vector<double> gen(unsigned int p_size)  = 0;

protected:
  std::shared_ptr<RandomUniform>  m_pUniform;
  double                          m_mu;
  double                          m_sig;
};
}

#endif // RANDOMNORMAL_H
