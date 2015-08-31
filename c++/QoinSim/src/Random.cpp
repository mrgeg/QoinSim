#include "Random.h"

namespace QOINSIM {

const std::map<std::string, Random::ERandomVarType>
Random::s_typeMap = {
  {"UniformMT",    Random::E_UniformMT},
  {"UniformSobol", Random::E_UniformSobol1111},
  {"NormalCNINV",  Random::E_NormalCNINV},
  {"Exponential",  Random::E_Exponential},
  {"NormalBox",    Random::E_NormalBox},
  {"Poisson",      Random::E_Poisson}
};

}
