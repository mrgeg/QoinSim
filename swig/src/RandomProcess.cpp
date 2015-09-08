#include "RandomProcess.h"

namespace QOINSIM {

const std::map<std::string, RandomProcess::EProcessType>
RandomProcess::s_typeMap = {
  {"Poisson", RandomProcess::E_Poisson},
  {"Hawkes",  RandomProcess::E_Hawkes}
};

}
