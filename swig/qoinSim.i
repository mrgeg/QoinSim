%module PyQoinSim
%{
#include "RandomVarInt.h"
%}

%include "std_string.i"
%include "std_vector.i"


namespace std{
  %template(VectorDouble) vector<double>;
}

namespace QOINSIM {
class RandomVarInt{
  public:
    RandomVarInt();
    ~RandomVarInt();

  public:
    double getRandom(std::string p_type);
    std::vector<double> getRandom(std::string p_type, unsigned int p_size);
};
}
