#ifndef RANDOMVARENV_H
#define RANDOMVARENV_H

#include "Random.h"
#include "Misc.h"

namespace QOINSIM {

struct RandomConfig : public IConfig {

RandomConfig (){
  type      = Random::E_MAX;
  unif_type = Random::E_UniformMT;
  norm_mu   = 0.;
  norm_sig  = 1.;
  sobolDim  = 0;
  expo_lam  = 0.5;
}

Random::ERandomVarType  type;
Random::ERandomVarType  unif_type;
unsigned int            sobolDim;
double                  norm_mu;
double                  norm_sig;
double                  expo_lam;

protected:
  void parse(){
    type = stringToType(m_map["TYPE"], Random::s_typeMap, true);

    if (m_map.find("SOBOLDIM") != m_map.end())
      sobolDim = std::stoi(m_map["SOBOLDIM"]);
  }

  bool isValid(){
    return true;
  }
};

class RandomVarEnv {
public:
  static RandomVarEnv& instance();

public:
  double                    getRandom(Random::ERandomVarType p_type);
  std::vector<double>       getRandom(Random::ERandomVarType p_type, unsigned int p_size);
  void                      add(const RandomConfig& p_config);
  std::shared_ptr<Random>   getRandomVar(Random::ERandomVarType p_type);

protected:
  inline explicit RandomVarEnv(){}
  virtual ~RandomVarEnv(){
    delete m_pInstance;
  }

private:
  bool contains(Random::ERandomVarType p_type) const { return m_randomVars.find(p_type) != m_randomVars.end(); }


private:
  inline explicit RandomVarEnv(RandomVarEnv const&){}
  inline RandomVarEnv& operator=(RandomVarEnv const&) { return *this; }

private:
  static RandomVarEnv* m_pInstance;

private:
  std::map<Random::ERandomVarType, std::shared_ptr<Random>> m_randomVars;
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
