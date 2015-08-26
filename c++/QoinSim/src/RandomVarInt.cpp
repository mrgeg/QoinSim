#include "RandomVarInt.h"
#include "RandomVarEnv.h"

namespace QOINSIM {
double
RandomVarInt::getRandom(std::vector<std::string> p_args){
  RandomVarEnv& l_env = RandomVarEnv::instance();

  RandomConfig l_config;
  l_config.init(p_args);
  l_env.add(l_config);

  return l_env.getRandom(l_config.type);
}

std::vector<double>
RandomVarInt::getRandom(std::vector<std::string> p_args, unsigned int p_size){
  RandomVarEnv& l_env = RandomVarEnv::instance();

  RandomConfig l_config;
  l_config.init(p_args);
  l_env.add(l_config);

  return l_env.getRandom(l_config.type, p_size);
}
}
