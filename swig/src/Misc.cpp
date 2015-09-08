#include "Misc.h"

namespace QOINSIM {

std::vector<std::string>
split(std::string p_str, std::string p_sep){
  size_t                    l_pos = 0;
  std::string               l_token;
  std::vector<std::string>  l_res;

  while ((l_pos = p_str.find(p_sep))!=std::string::npos){
    l_token = p_str.substr(0, l_pos);
    l_res.push_back(l_token);
    p_str.erase(0, l_pos + p_sep.length());
  }
  l_res.push_back(p_str);

  return l_res;
}

std::map<std::string, std::string>
arrayArgstoMap(std::vector<std::string> p_args, std::string p_sep){
  std::map<std::string, std::string> l_map;

  for (unsigned int l_i = 0; l_i < p_args.size(); l_i++){
    std::vector<std::string> l_vect = split(p_args[l_i], p_sep);
    if (l_vect.size() > 2)
      throw "arg def. is wrong";

    l_map[l_vect[0]]=l_vect[1];
  }

  return l_map;
}
}
