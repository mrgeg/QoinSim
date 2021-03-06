%module PyQoinSim
%{
#include "RandomVarInt.h"
%}

%include "std_string.i"
%include "std_vector.i"


namespace std{
  %template(VectorDouble) vector<double>;
  %template(VectorString) vector<string>;
  %template(VecVecDouble) vector< vector<double> >;
}

using namespace std;

namespace QOINSIM {
class RandomVarInt{
  public:
    RandomVarInt();
    ~RandomVarInt();

  public:
    double getRandom(std::vector<std::string> p_args);
    std::vector<double> getRandom(std::vector<std::string> p_args, unsigned int p_size);
    std::vector<std::vector<double> > getProcess(std::vector<std::string> p_args, double p_timeMax, unsigned int p_discNumber, unsigned int p_pathsNumber);
};
}
