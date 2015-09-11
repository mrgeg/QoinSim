#include "RandomVarInt.h"
#include "RandomVarEnv.h"

namespace QOINSIM {
double
RandomVarInt::getRandom(std::vector<std::string> p_args){
  RandomVarEnv& l_env = RandomVarEnv::instance();

  RandomVarConfig l_config;
  l_config.init(p_args);
  l_env.add(l_config);

  return l_env.getRandom(l_config.type);
}

std::vector<double>
RandomVarInt::getRandom(std::vector<std::string> p_args, unsigned int p_size){
  RandomVarEnv& l_env = RandomVarEnv::instance();

  RandomVarConfig l_config;
  l_config.init(p_args);
  l_env.add(l_config);

  return l_env.getRandom(l_config.type, p_size);
}

std::vector<std::vector<double>>
RandomVarInt::getProcess(std::vector<std::string> p_args, double p_timeMax, unsigned int p_discNumber, unsigned int p_pathsNumber){
  RandomVarEnv& l_env = RandomVarEnv::instance();

  RandomProcessConfig l_config;
  l_config.init(p_args);
  l_env.add(l_config);

  std::shared_ptr<RandomProcess> l_process = l_env.getRandomProc(l_config.type);

  return l_env.mvCast(l_process->generatePaths(p_timeMax, p_discNumber, p_pathsNumber));
}
}
