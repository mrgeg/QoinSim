#include "RandomVarInt.h"
#include "RandomVarEnv.h"

namespace QOINSIM {
double
RandomVarInt::getRandom(std::vector<std::string> p_args){
  RandomVarEnv& l_env = RandomVarEnv::instance();

  return l_env.getRandom(p_args);
}
std::vector<double>
RandomVarInt::getRandom(std::vector<std::string> p_args, unsigned int p_size){
  RandomVarEnv& l_env = RandomVarEnv::instance();

  return l_env.getRandom(p_args, p_size);
}
}
