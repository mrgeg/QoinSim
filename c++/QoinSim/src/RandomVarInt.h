#ifndef RANDOMVARINT_H
#define RANDOMVARINT_H

#include <vector>
#include <string>

namespace QOINSIM {
class RandomVarInt{
public:
  RandomVarInt(){}
  ~RandomVarInt(){}

public:
  double getRandom(std::vector<std::string> p_args);
  std::vector<double> getRandom(std::vector<std::string> p_args, unsigned int p_size);
  std::vector<std::vector<double> > getProcess(std::vector<std::string> p_args, double p_timeMax, unsigned int p_discNumber, unsigned int p_pathsNumber);
};
}

#endif // RANDOMVARINT_H
