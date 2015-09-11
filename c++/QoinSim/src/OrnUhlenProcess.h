#ifndef ORNUHLENPROCESS_H
#define ORNUHLENPROCESS_H

#include <ItoDiffusion.h>
#include <EulerDiscretization.h>
#include <RandomProcess.h>

namespace QOINSIM {

class OrnUhlenProcess : public RandomProcess {
public:
  OrnUhlenProcess(const std::shared_ptr<RandomNormal>& p_pNorm,
    double p_x0, double p_xinf, double p_slope, double p_sigma);

  virtual ~OrnUhlenProcess() {}

public:
  matrix<double> generatePaths(int p_pathsNumber, const std::vector<double>& p_disc);
  matrix<double> generatePaths(double p_timeMax, int p_discNumber, int p_pathsNumber);

private:
  class OrnUhlenDiffusion : public ItoDiffusion {
  public:
    OrnUhlenDiffusion(double p_x0, double p_xinf,
      double p_slope, double p_sigma);

    virtual ~OrnUhlenDiffusion() {}

  public:
    vector<double> init();
    vector<double> mu(double p_time, const vector<double>& p_x);
    matrix<double> sigma(double p_time, const vector<double>& p_x);

  private:
    double m_x0;
    double m_xinf;
    double m_slope;
    double m_sigma;
  };

private:
  std::shared_ptr<ItoDiffusion> m_diff;
  EulerDiscretization           m_euler;
};
}

#endif // ORNUHLENPROCESS_H
