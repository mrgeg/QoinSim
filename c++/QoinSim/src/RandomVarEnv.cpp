#include "RandomVarEnv.h"
#include "RandomUniformMT.h"
#include "RandomUniformSobol.h"
#include "Misc.h"

namespace QOINSIM {

RandomVarEnv* RandomVarEnv::m_pInstance = 0;

const std::map<std::string, Random::ERandomVarType>
RandomVarEnv::s_typeMap = {
  {"UniformMT",    Random::E_UniformMT},
  {"UniformSobol", Random::E_UniformSobol1111}
};

RandomVarEnv&
RandomVarEnv::instance(){
  if (!m_pInstance)
    m_pInstance = new RandomVarEnv;

  return *m_pInstance;
}

std::unique_ptr<Random>
RandomVarFactory::buildUnique(const RandomConfig& p_config) {
  switch(p_config.type) {
  case Random::E_UniformMT:
    return std::unique_ptr<Random>(new RandomUniformMT);
  case Random::E_UniformSobol1111:
    return std::unique_ptr<Random>(new RandomUniformSobol(p_config.sobolDim));
  default:
    throw "type not implemented";
  }
}

std::shared_ptr<Random>
RandomVarFactory::buildShared(const RandomConfig& p_config) {
  switch(p_config.type) {
  case Random::E_UniformMT:
    return std::shared_ptr<Random>(new RandomUniformMT);
  case Random::E_UniformSobol1111:
    return std::shared_ptr<Random>(new RandomUniformSobol(p_config.sobolDim));
  default:
    throw "type not implemented";
  }
}

double
RandomVarEnv::getRandom(const std::vector<std::string>& p_args) {
  RandomConfig l_config; l_config.init(p_args);

  if (m_randomVars.find(l_config.type) == m_randomVars.end())
    m_randomVars[l_config.type] = RandomVarFactory::buildUnique(l_config);

  return m_randomVars[l_config.type]->gen();
}

std::vector<double>
RandomVarEnv::getRandom(const std::vector<std::string>& p_args, unsigned int p_size) {
  RandomConfig l_config; l_config.init(p_args);

  if (m_randomVars.find(l_config.type) == m_randomVars.end())
    m_randomVars[l_config.type] = RandomVarFactory::buildUnique(l_config);

  return m_randomVars[l_config.type]->gen(p_size);
}
}
