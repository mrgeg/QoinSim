#ifndef RANDOMVARENV_H
#define RANDOMVARENV_H

#include "Random.h"
#include "RandomProcess.h"
#include "Misc.h"

namespace QOINSIM {

struct RandomVarConfig : public IConfig {
  RandomVarConfig (){
    type      = Random::E_MAX;
    unif_type = Random::E_UniformMT;
    norm_mu   = 0.;
    norm_sig  = 1.;
    sobolDim  = 0;
    expo_lam  = 0.5;
    pois_lam  = 2.;
  }

  Random::ERandomVarType  type;
  Random::ERandomVarType  unif_type;
  unsigned int            sobolDim;
  double                  norm_mu;
  double                  norm_sig;
  double                  expo_lam;
  double                  pois_lam;

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

struct RandomProcessConfig : public IConfig {
  RandomProcessConfig() {
    unif_type   = Random::E_UniformMT;
    norm_type   = Random::E_NormalCNINV;
    pois_lam    = 5.;
    hawk_mu     = 0.;
    hawk_alpha  = 1.;
    hawk_beta   = 1.;
    ornuhn_x0   = 1.;
    ornuhn_xinf = 1.;
    ornuhn_slope= 1.;
    ornuhn_sigma= 1.;
  }

  RandomProcess::EProcessType type;
  Random::ERandomVarType      unif_type;
  Random::ERandomVarType      norm_type;
  double                      pois_lam;
  double                      hawk_mu;
  double                      hawk_alpha;
  double                      hawk_beta;
  double                      ornuhn_x0;
  double                      ornuhn_xinf;
  double                      ornuhn_slope;
  double                      ornuhn_sigma;

protected:
  void parse() {
    type = stringToType(m_map["TYPE"], RandomProcess::s_typeMap, true);
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
  void                      add(const RandomVarConfig& p_config);
  std::shared_ptr<Random>   getRandomVar(Random::ERandomVarType p_type);

public:
  void                             add(const RandomProcessConfig& p_config);
  std::shared_ptr<RandomProcess>   getRandomProc(RandomProcess::EProcessType p_type);
  std::vector<std::vector<double>> mvCast(const matrix<double>& p_matrix);

protected:
  inline explicit RandomVarEnv(){}
  virtual ~RandomVarEnv(){
    delete m_pInstance;
  }

private:
  bool contains(Random::ERandomVarType p_type)      const { return m_randomVars.find(p_type) != m_randomVars.end(); }
  bool contains(RandomProcess::EProcessType p_type) const { return m_randomProcs.find(p_type) != m_randomProcs.end(); }

private:
  inline explicit RandomVarEnv(RandomVarEnv const&){}
  inline RandomVarEnv& operator=(RandomVarEnv const&) { return *this; }

private:
  static RandomVarEnv* m_pInstance;

private:
  std::map<Random::ERandomVarType,      std::shared_ptr<Random>>        m_randomVars;
  std::map<RandomProcess::EProcessType, std::shared_ptr<RandomProcess>> m_randomProcs;
};

class RandomVarFactory {
public:
  static std::unique_ptr<Random>          buildUnique(const RandomVarConfig& p_config);
  static std::shared_ptr<Random>          buildShared(const RandomVarConfig& p_config);
  static std::shared_ptr<RandomUniform>   getSharedUniform(Random::ERandomVarType p_type);

private:
  RandomVarFactory() {}
};

class RandomProcessFactory {
public:
  static std::shared_ptr<RandomProcess> buildShared(const RandomProcessConfig& p_config);

private:
  RandomProcessFactory(){}
};
}

#endif // RANDOMVARENV_H
