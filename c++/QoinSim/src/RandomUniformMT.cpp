#include "RandomUniformMT.h"

namespace QOINSIM {

const long          RandomUniformMT::s_seed      = 457;
const double        RandomUniformMT::s_invMax    = 1.0 / 4294967296.0;
const long          RandomUniformMT::s_n         = 624;
const long          RandomUniformMT::s_m         = 397;
const long          RandomUniformMT::s_initMult  = 69069;
const unsigned long RandomUniformMT::s_initMask  = 0xffffffff;
const unsigned long RandomUniformMT::s_mag[2]    = {0x0, 0x9908b0df};
const unsigned long RandomUniformMT::s_upperMask = 0x80000000;
const unsigned long RandomUniformMT::s_lowerMask = 0x7fffffff;
const unsigned long RandomUniformMT::s_tempMaskB = 0x9d2c5680;
const unsigned long RandomUniformMT::s_tempMaskC = 0xefc60000;

RandomUniformMT::RandomUniformMT() : m_stateVector(s_n) {
  reset();
  generate();
}

RandomUniformMT::~RandomUniformMT() {
  m_stateVector.clear();
}

void
RandomUniformMT::reset() {
  m_stateVector[0] = s_seed & s_initMask;

  for (m_index = 1; m_index < s_n; m_index++) {
    m_stateVector[m_index] = (s_initMult * m_stateVector[m_index-1]) &
                             s_initMask;
  }
}

double
RandomUniformMT::gen() {
  unsigned long l_uUniform;
  double        l_fUniform;

  if (m_index >= s_n) {
    RandomUniformMT::generate();
    m_index = 0;
  }

  l_uUniform  = m_stateVector[m_index++];
  l_uUniform ^= shiftU(l_uUniform);
  l_uUniform ^= shiftS(l_uUniform) & s_tempMaskB ;
  l_uUniform ^= shiftT(l_uUniform) & s_tempMaskC ;
  l_uUniform ^= shiftL(l_uUniform) ;
  l_fUniform  = ((double) l_uUniform) * s_invMax ;

  return l_fUniform ;
}

std::vector<double>
RandomUniformMT::gen(unsigned int p_size){
  std::vector<double> l_res(p_size);

  for (unsigned int l_i = 0; l_i < p_size; l_i++){
    l_res[l_i] = gen();
  }

  return l_res;
}

void
RandomUniformMT::generate() {
  unsigned long l_uniform;
  size_t        l_i;

  for (l_i = 0; l_i < s_n - s_m; l_i++) {
    l_uniform          = (m_stateVector[l_i] & s_upperMask) | (m_stateVector[l_i + 1] & s_lowerMask);
    m_stateVector[l_i] = m_stateVector[l_i + s_m] ^ (l_uniform >> 1) ^ s_mag[l_uniform & 0x1];
  }

  for(; l_i < s_n - 1; l_i++) {
    l_uniform          = (m_stateVector[l_i] & s_upperMask) | (m_stateVector[l_i + 1] & s_lowerMask);
    m_stateVector[l_i] = m_stateVector[l_i + s_m - s_n] ^ (l_uniform >> 1) ^ s_mag[l_uniform & 0x1];
  }

  l_uniform              = (m_stateVector[s_n - 1] & s_upperMask) | (m_stateVector[0] & s_lowerMask);
  m_stateVector[s_n - 1] = m_stateVector[s_m - 1] ^ (l_uniform >> 1) ^ s_mag[l_uniform & 0x1];
}
}
