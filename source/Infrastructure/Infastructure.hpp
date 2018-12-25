#ifndef __INFRASTRUCTURE_H__
#define __INFRASTRUCTURE_H__

#include <cstdint>
#include <cmath>

namespace Infrastructure {

  double Log2 (double n);

  unsigned int Log2ceil(uint64_t i);
  
  bool IsPower2(const long x);

  //return the exponent base 2
  inline unsigned long POW2(int exponent) {

    return (1UL) << exponent;
}

  //Return ceil
  inline int64_t CEIL(double a) {
    return(int64_t) ceil(a);


}






}
#endif
