#include "RandomVarInt.h"
#include "RandomVarEnv.h"

namespace QOINSIM {
double
RandomVarInt::getRandom(std::string p_type){
  RandomVarEnv& l_env = RandomVarEnv::instance();

  return l_env.getRandom(p_type);
}
std::vector<double>
RandomVarInt::getRandom(std::string p_type, unsigned int p_size){
  RandomVarEnv& l_env = RandomVarEnv::instance();

  return l_env.getRandom(p_type, p_size);
}

//extern "C"
//{
//  double getRandom(char* p_type){
//    RandomVarInt l_int;
//    return l_int.getRandom(p_type);
//  }
//
//  double* getRandomVect(char* p_type, unsigned int p_size) {
//    RandomVarInt l_int;
//    return l_int.getRandom(p_type, p_size);
//  }
//}
}
