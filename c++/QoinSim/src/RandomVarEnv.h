#ifndef RANDOMVARENV_H
#define RANDOMVARENV_H

#include "Random.h"
#include "Misc.h"

namespace QOINSIM {
class RandomVarFactory {
public:
  static std::unique_ptr<Random> buildUnique(Random::ERandomVarType p_type);
  static std::shared_ptr<Random> buildShared(Random::ERandomVarType p_type);
private:
  RandomVarFactory() {}
};

class RandomVarEnv {
public:
  static RandomVarEnv& instance();

public:
  double getRandom(std::string p_type);
  double* getRandom(std::string p_type, unsigned int p_size);

public:
  static const std::map<std::string, Random::ERandomVarType> s_typeMap;

protected:
  inline explicit RandomVarEnv(){}
  virtual ~RandomVarEnv(){
    m_pInstance = 0; }

private:
  inline explicit RandomVarEnv(RandomVarEnv const&){}
  inline RandomVarEnv& operator=(RandomVarEnv const&) { return *this; }

private:
  static RandomVarEnv* m_pInstance;

private:
  std::map<Random::ERandomVarType, std::unique_ptr<Random>> m_randomVars;
};

RandomVarEnv* RandomVarEnv::m_pInstance = 0;

const std::map<std::string, Random::ERandomVarType>
RandomVarEnv::s_typeMap = {
{"UniformMT", Random::E_UniformMT},
{"UniformSobol366", Random::E_UniformSobol366},
{"UniformSobol1111", Random::E_UniformSobol1111}
};

RandomVarEnv&
RandomVarEnv::instance(){
  if (!m_pInstance)
    m_pInstance = new RandomVarEnv;

  return *m_pInstance;
}

}

#endif // RANDOMVARENV_H
