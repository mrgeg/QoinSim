#ifndef RANDOMNORMALBOX_H
#define RANDOMNORMALBOX_H

#include <RandomNormal.h>
#include <RandomExpo.h>
#include "Misc.h"

namespace QOINSIM {

class RandomNormalBox : public RandomNormal {
public:
  RandomNormalBox(const std::shared_ptr<RandomUniform>&  p_pUniform,
                    double p_mu = 0., double p_sig = 1.);

  virtual ~RandomNormalBox() {}

public:
  double              gen();
  std::vector<double> gen(unsigned int p_size);
  void                reset();

private:
  double                      m_r2, m_theta;
  bool                        m_flag;
  std::shared_ptr<RandomExpo> m_pExpo;
};
}
#endif // RANDOMNORMALBOX_H
