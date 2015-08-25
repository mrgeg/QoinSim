#include <iostream>
#include "RandomVarInt.h"

using namespace std;
using namespace QOINSIM;

int main()
{
    cout << "Hello world!" << endl;

    std::vector<std::string> l_args = {"TYPE:UniformSobol","SOBOLDIM:1100"};

    QOINSIM::RandomVarInt l_rdInt;

    std::vector<double> l_rdm = l_rdInt.getRandom(l_args,1000);

    return 0;
}
