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
    double getRandom(std::string p_type);
    std::vector<double> getRandom(std::string p_type, unsigned int p_size);

};
}

#endif // RANDOMVARINT_H
