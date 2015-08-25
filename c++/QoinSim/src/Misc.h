#ifndef __MISC_H
#define __MISC_H

#include <algorithm>
#include <map>
#include <list>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <memory>

namespace QOINSIM {

template<typename T>
T stringToType(std::string p_type, const std::map<std::string, T>& p_map, bool p_matchCase = false){
  typename std::map<std::string, T>::const_iterator l_it = p_map.begin();
  for (; l_it != p_map.end(); l_it++){
    if (l_it->first == p_type)
      return l_it->second;
  }

  throw "unknown type";
}

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... p_args){
    return std::unique_ptr<T>(new T(std::forward<Args>(p_args)...));
}

std::vector<std::string>
split(std::string p_str, std::string p_sep = ",");

std::map<std::string, std::string>
arrayArgstoMap(std::vector<std::string> p_args, std::string p_sep = ":");

struct IConfig {
void init(std::vector<std::string> p_args){
  m_map = arrayArgstoMap(p_args);

  if (!isValid())
    throw "config failed";

  parse();
}

protected:
  virtual void parse()    = 0;

  virtual bool isValid()  = 0;

protected:
  std::map<std::string,std::string> m_map;

};

}

#endif
