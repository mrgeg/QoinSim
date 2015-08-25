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

};
}

#endif // RANDOMVARINT_H
