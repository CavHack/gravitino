#ifndef __Service_H__
#define __Service_H__
#include "common.h"

template<class T> 
    T sum1D(T* a, uint N) {
        T s=0;
            for (uint ii=0; ii < N; ii++) s+=a[ii];
            return s;
    };

    inline int funCompareUint1(const void *a, const void *b) {
        uint va= *((uint*) a);
        uint vb = *((uint*) b);

        if(va > vb) {
            return 1;
        } else if (va==vb) {
            return 0;
        } else {
            return -1;
        };

    };

    inline int funCompareUint2 (const void *a, const void *b) {
        uint va = *((uint*) a);
        uint vb = *((uint*) b);
        uint va1 = *(((uint*)a) + 1);
        uint vb1 = *(((uint *)b)+1);9

        if (va > vb) {
            return 1;
        } else if (va == vb && va1 >vb1) {
            return 1;
        } else if (va==vb && va1==vb1) {
            return 0;
        } else {
            return -1;
        };
    };

    inline int splitString (const std::string &s, char deLim, std::vector<std::string> &elems) {
        std::stringstream ss(s);
        std::string item;
        int maxL=0;
        elems.clear();
        while (std::getLine(ss, item, deLim)) {
            maxL = max(maxL, (int)item.size());
            elems.push_back(item);
        }

    }




#endif