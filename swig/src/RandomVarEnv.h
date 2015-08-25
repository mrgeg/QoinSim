#ifndef RANDOMVARENV_H
#define RANDOMVARENV_H

#include "Random.h"
#include "Misc.h"

namespace QOINSIM {

class RandomVarEnv {
public:
  static RandomVarEnv& instance();

public:
  double getRandom(const std::vector<std::string>& p_args);
  std::vector<double> getRandom(const std::vector<std::string>& p_args, unsigned int p_size);

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

struct RandomConfig : public IConfig {

RandomConfig (){
  type      = Random::E_MAX;
  sobolDim  = 0;
}

Random::ERandomVarType  type;
unsigned int            sobolDim;

protected:
  void parse(){
    type = stringToType(m_map["TYPE"], RandomVarEnv::s_typeMap, true);

    if (m_map.find("SOBOLDIM") != m_map.end())
      sobolDim = std::stoi(m_map["SOBOLDIM"]);
  }

  bool isValid(){
    return true;
  }
};

class RandomVarFactory {
public:
  static std::unique_ptr<Random> buildUnique(const RandomConfig& p_config);
  static std::shared_ptr<Random> buildShared(const RandomConfig& p_config);
private:
  RandomVarFactory() {}
};
}

#endif // RANDOMVARENV_H
