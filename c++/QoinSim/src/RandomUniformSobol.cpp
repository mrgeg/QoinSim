#include "RandomUniformSobol.h"

namespace QOINSIM {

const unsigned int RandomUniformSobol::s_maxBit = MAXBIT;
const unsigned int RandomUniformSobol::s_maxDim = MAXDIM;
const unsigned int RandomUniformSobol::s_skip   = 9685;

unsigned int       RandomUniformSobol::s_poly[MAXDIM];
bool               RandomUniformSobol::s_incl[MAXDIM];
unsigned int       RandomUniformSobol::s_atMost;
unsigned int       RandomUniformSobol::s_maxcol;
unsigned int       RandomUniformSobol::s_v[MAXDIM][MAXBIT];
double             RandomUniformSobol::s_recipd;

RandomUniformSobol::s_init RandomUniformSobol::s_initializer;

RandomUniformSobol::RandomUniformSobol(unsigned int p_dim)
: m_seed(1), m_dim(p_dim), m_index(0), m_stateVector(p_dim) {
init();
}

RandomUniformSobol::~RandomUniformSobol(){
}

int RandomUniformSobol::bitHigh(int p_n){
  int l_bit = 0;

  while (0 < p_n){
    l_bit += 1;
    p_n   /= 2;
  }

  return l_bit;
}

int RandomUniformSobol::bitLow(int p_n){
  int l_bit = 0;
  int l_n2;

  while (true){
    l_bit += 1;
    l_n2   = p_n / 2;

    if (p_n == 2 * l_n2)
      break;

    p_n = l_n2;
  }

  return l_bit;
}

void RandomUniformSobol::init(){
    unsigned int l_i, l_j, l_j2, l_m, l_k, l_newV, l_l;

    for (l_i = 1; l_i < m_dim; l_i++) {
      l_j = s_poly[l_i];
      l_m = 0;
      while (true) {
        l_j /= 2;
        if (l_j <= 0)
          break;

        l_m += 1;
      }

      l_j = s_poly[l_i];
      for (l_k = l_m - 1; l_k >= 0; l_k--) {
        l_j2        = l_j / 2;
        s_incl[l_k] = (l_j != (2 * l_j2));
        l_j         = l_j2;
      }

      for (l_j = l_m; l_j < s_maxcol; l_j++) {
        l_newV = s_v[l_i][l_j - l_m];
        l_l    = 1;

        for (l_k = 0; l_k < l_m; l_k++) {
          l_l *= 2;
          if (s_incl[l_k])
            l_newV = (l_newV ^ (l_l * s_v[l_i][l_j - l_k - 1]));
        }

        s_v[l_i][l_j] = l_newV;
      }
    }

    l_l = 1;
    for (l_j = s_maxcol - 2; l_j >= 0; l_j--) {
      l_l *= 2;
      for (l_i = 0; l_i < m_dim; l_i++)
        s_v[l_i][l_j] = s_v[l_i][l_j] * l_l;
    }

    s_recipd = 1.0 / ((double)(2 * l_l));

    reset();
}

void RandomUniformSobol::generate(){
  unsigned int l_i, l_l;

  m_seed += 1;
  l_l = bitLow(m_seed);

  for (l_i = 0; l_i < m_dim; l_i++){
    m_stateVector[l_i] = m_stateVector[l_i] ^ s_v[l_i][l_l-1];
  }

  m_index = 0;
}

void RandomUniformSobol::reset(){
  m_stateVector.resize(m_dim, 0);
  unsigned int l_i, l_l;

  for (m_seed = 1; m_seed <= s_skip; m_seed++){
    l_l = bitLow(m_seed);
    for (l_i = 0; l_i < m_dim; l_i++){
      m_stateVector[l_i] = m_stateVector[l_i] ^ s_v[l_i][l_l-1];
    }
  }

  m_index = 0;
}

double RandomUniformSobol::gen(){
  if (++m_index!=m_dim)
    return m_stateVector[m_index] * s_recipd;

  generate();

  return gen();
}

std::vector<double>
RandomUniformSobol::gen(unsigned int p_size){
  std::vector<double> l_res(p_size);

  if (p_size > m_dim)
    throw "size is bigger than sobol dimension";

  for (unsigned int l_i = 0; l_i < p_size; l_i++){
    l_res.push_back(gen());
  }

  return l_res;
}
}
