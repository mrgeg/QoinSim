#ifndef RANDOMUNIFORMMT_H
#define RANDOMUNIFORMMT_H

#include <Random.h>

namespace QOINSIM {
class RandomUniformMT : public RandomUniform{
  public:
    RandomUniformMT();
    virtual ~RandomUniformMT();

  public:
    void                reset();
    double              gen();
    std::vector<double> gen(unsigned int p_size);

  protected:
    unsigned long shiftU(unsigned long& r_mask) const { return (r_mask >> 11); };
    unsigned long shiftS(unsigned long& r_mask) const { return (r_mask << 7); };
    unsigned long shiftT(unsigned long& r_mask) const { return (r_mask << 15); };
    unsigned long shiftL(unsigned long& r_mask) const { return (r_mask >> 18); };

    void generate();

  protected:
    std::vector<unsigned long>  m_stateVector;
    long                        m_index;

  protected:
    static const long                  s_seed;
    static const double                s_invMax;
    static const long                  s_n;
    static const long                  s_m;
    static const long                  s_initMult;
    static const unsigned long         s_initMask;
    static const unsigned long         s_mag[2];
    static const unsigned long         s_upperMask;
    static const unsigned long         s_lowerMask;
    static const unsigned long         s_tempMaskB;
    static const unsigned long         s_tempMaskC;
};
}

#endif // RANDOMUNIFORMMT_H
