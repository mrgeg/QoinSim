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
    delete m_pInstance;
  }

private:
  inline explicit RandomVarEnv(RandomVarEnv const&){}
  inline RandomVarEnv& operator=(RandomVarEnv const&) { return *this; }

private:
  static RandomVarEnv* m_pInstance;

private:
  std::map<Random::ERandomVarType, std::unique_ptr<Random>> m_randomVars;
};
}

#endif // RANDOMVARENV_H
