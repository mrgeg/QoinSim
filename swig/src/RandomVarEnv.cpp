#include "RandomVarEnv.h"
#include "RandomUniformMT.h"
#include "RandomUniformSobol.h"
#include "RandomNormalCNINV.h"
#include "RandomExpo.h"
#include "RandomNormalBox.h"
#include "RandomPoisson.h"
#include "Misc.h"

namespace QOINSIM {

RandomVarEnv* RandomVarEnv::m_pInstance = 0;

RandomVarEnv&
RandomVarEnv::instance() {
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
  case Random::E_NormalCNINV: {
    RandomVarEnv&                   l_env  = RandomVarEnv::instance();
    std::shared_ptr<RandomUniform>  l_unif =
      std::dynamic_pointer_cast<RandomUniform>(l_env.getRandomVar(p_config.unif_type));

    return std::unique_ptr<Random>(new RandomNormalCNINV(l_unif, p_config.norm_mu, p_config.norm_sig));
    }
  case Random::E_Exponential: {
    RandomVarEnv&                   l_env  = RandomVarEnv::instance();
    std::shared_ptr<RandomUniform>  l_unif =
      std::dynamic_pointer_cast<RandomUniform>(l_env.getRandomVar(p_config.unif_type));

    return std::unique_ptr<Random>(new RandomExpo(l_unif, p_config.expo_lam));
    }
  case Random::E_NormalBox: {
    RandomVarEnv&                   l_env  = RandomVarEnv::instance();
    std::shared_ptr<RandomUniform>  l_unif =
      std::dynamic_pointer_cast<RandomUniform>(l_env.getRandomVar(p_config.unif_type));

    return std::unique_ptr<Random>(new RandomNormalBox(l_unif, p_config.norm_mu, p_config.norm_sig));
    }
  case Random::E_Poisson: {
    RandomVarEnv&                   l_env  = RandomVarEnv::instance();
    std::shared_ptr<RandomUniform>  l_unif =
      std::dynamic_pointer_cast<RandomUniform>(l_env.getRandomVar(p_config.unif_type));

    return std::unique_ptr<Random>(new RandomPoisson(l_unif, p_config.pois_lam));
    }
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
  case Random::E_NormalCNINV: {
    RandomVarEnv&                   l_env  = RandomVarEnv::instance();
    std::shared_ptr<RandomUniform>  l_unif =
      std::dynamic_pointer_cast<RandomUniform>(l_env.getRandomVar(p_config.unif_type));

    return std::shared_ptr<Random>(new RandomNormalCNINV(l_unif, p_config.norm_mu, p_config.norm_sig));
    }
  case Random::E_Exponential: {
    RandomVarEnv&                   l_env  = RandomVarEnv::instance();
    std::shared_ptr<RandomUniform>  l_unif =
      std::dynamic_pointer_cast<RandomUniform>(l_env.getRandomVar(p_config.unif_type));

    return std::shared_ptr<Random>(new RandomExpo(l_unif, p_config.expo_lam));
    }
  case Random::E_NormalBox: {
    RandomVarEnv&                   l_env  = RandomVarEnv::instance();
    std::shared_ptr<RandomUniform>  l_unif =
      std::dynamic_pointer_cast<RandomUniform>(l_env.getRandomVar(p_config.unif_type));

    return std::shared_ptr<Random>(new RandomNormalBox(l_unif, p_config.norm_mu, p_config.norm_sig));
    }
  case Random::E_Poisson: {
    RandomVarEnv&                   l_env  = RandomVarEnv::instance();
    std::shared_ptr<RandomUniform>  l_unif =
      std::dynamic_pointer_cast<RandomUniform>(l_env.getRandomVar(p_config.unif_type));

    return std::shared_ptr<Random>(new RandomPoisson(l_unif, p_config.pois_lam));
    }
  default:
    throw "type not implemented";
  }
}

double
RandomVarEnv::getRandom(Random::ERandomVarType p_type){
  if (!contains(p_type))
    throw "random generator not found";

  return m_randomVars[p_type]->gen();
}

std::vector<double>
RandomVarEnv::getRandom(Random::ERandomVarType p_type, unsigned int p_size){
  if (!contains(p_type))
    throw "random generator not found";

  return m_randomVars[p_type]->gen(p_size);
}

void
RandomVarEnv::add(const RandomConfig& p_config){
  if (contains(p_config.type))
    return;

  if (p_config.unif_type != Random::E_MAX){
    RandomConfig l_config = p_config;
    l_config.type         = p_config.unif_type;
    l_config.unif_type    = Random::E_MAX;
    add(l_config);
  }

  m_randomVars[p_config.type] = RandomVarFactory::buildShared(p_config);
}

std::shared_ptr<Random>
RandomVarEnv::getRandomVar(Random::ERandomVarType p_type){
 return m_randomVars[p_type];
}
}
