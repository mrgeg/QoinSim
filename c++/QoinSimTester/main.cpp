#include <iostream>
#include <fstream>
#include "PoissonProcess.h"
#include "HawkesProcess.h"
#include "RandomVarEnv.h"
#include "boost/numeric/ublas/matrix.hpp"

using namespace std;
using namespace QOINSIM;

int main()
{
  cout << "Hello world!" << endl;

//    std::vector<std::string> l_args = {"TYPE:UniformSobol","SOBOLDIM:1100"};
//
//    QOINSIM::RandomVarInt l_rdInt;
//
//    std::vector<double> l_rdm = l_rdInt.getRandom(l_args,1000);
  RandomVarConfig l_cfg;
  l_cfg.type = Random::E_UniformMT;

  std::shared_ptr<RandomUniform>  l_unif =
      std::dynamic_pointer_cast<RandomUniform>(RandomVarFactory::buildShared(l_cfg));

  HawkesProcess l_hawkes(l_unif, 0.5, 0.1, 0.9);

  matrix<double> l_paths = l_hawkes.generatePaths(1., 100, 10);

  ofstream _file("path.txt");

  std::string l_line;

  for (int l_i = 0; l_i < l_paths.size1(); l_i++){
    l_line = "";
    for (int l_j = 0; l_j < l_paths.size2(); l_j++){
      l_line += std::to_string(l_paths(l_i, l_j)) + ",";
    }
    _file<<l_line<<std::endl;
  }
  _file.close();

  return 0;
}
