#ifndef SINGLETONHOLDER_H
#define SINGLETONHOLDER_H

#include "Misc.h"

namespace QOINSIM {
template<typename T>
class SingletonHolder{
  public:
    static T& instance();

  protected:
    inline ~SingletonHolder(){}
    inline explicit SingletonHolder(){}
    inline explicit SingletonHolder(SingletonHolder const&){}
    inline SingletonHolder& operator=(SingletonHolder const&){ return *this; }

  private:
    static std::unique_ptr<T> m_pInstance;
  private:
    static std::unique_ptr<T> createInstance();
};

template<typename T>
T& SingletonHolder<T>::instance(){
if (!m_pInstance)
  m_pInstance = createInstance();

return *SingletonHolder::m_pInstance;
}
template<typename T>
inline std::unique_ptr<T> createInstance(){
  return std::unique_ptr<T>(new T);
}
template<typename T>
typename std::unique_ptr<T> SingletonHolder<T>::m_pInstance = 0;
}
#endif // SINGLETONHOLDER_H
