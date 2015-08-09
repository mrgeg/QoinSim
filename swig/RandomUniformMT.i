%module RandomUniformMT
%{
#include "RandomUniformMT.h"
%}

namespace std {
	   %template(DoubleVector) vector<double>;
}

class RandomUniformMT {
  public:
    RandomUniformMT();
    virtual ~RandomUniformMT();

    void                reset();
    double              gen();
    std::vector<double> gen(int p_size);
};
