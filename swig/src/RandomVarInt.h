#ifndef RANDOMVARINT_H
#define RANDOMVARINT_H

namespace QOINSIM {
class RandomVarInt{
  public:
    RandomVarInt(){}
    ~RandomVarInt(){}

  public:
    double getRandom(char* p_type);
    double* getRandomVect(char* p_type, unsigned int p_size);

};
}

#endif // RANDOMVARINT_H
