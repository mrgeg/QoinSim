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
std::unique_ptr<T> make_unique(Args&&... p_args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(p_args)...));
}

#endif
