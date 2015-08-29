#include "HawkesProcess.h"

namespace QOINSIM {

HawkesProcess::
  HawkesProcess(const std::shared_ptr<RandomUniform>& p_unif,
  double p_mu, double p_alpha, double p_beta) : m_unif(p_unif), m_mu(p_mu), m_alpha(p_alpha), m_beta(p_beta)
  {}
}
