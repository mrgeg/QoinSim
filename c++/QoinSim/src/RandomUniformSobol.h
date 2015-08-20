#ifndef RANDOMUNIFORMSOBOL_H
#define RANDOMUNIFORMSOBOL_H

#include <Random.h>

//adapted from the excellent random generation page
//https://people.sc.fsu.edu/~jburkardt/cpp_src/sobol/sobol.html

namespace QOINSIM {

#define MAXDIM  1111
#define MAXBIT 30

class RandomUniformSobol : public RandomUniform {
  public:
    RandomUniformSobol(int p_dim);
    virtual ~RandomUniformSobol();

  public:
    void                reset();
    double              gen();
    std::vector<double> gen(unsigned int p_size);

  private:
    int                   m_dim;
    int                   m_index;
    std::vector<double>   m_stateVector;


  private:
    int bitHigh(int p_n);
    int bitLow(int p_n);

  private:
    static const int s_seed;
    static const int s_maxBit;
    static const int s_maxDim;

    static const int s_poly[MAXDIM];
    static const int s_polyDeg[MAXDIM];
    static const int s_v[MAXBIT][MAXDIM];

};
}

#endif // RANDOMUNIFORMSOBOL_H
