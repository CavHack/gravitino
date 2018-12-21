#ifndef __COMMON_H__
#define __COMMON_H__

//standard libs
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
#include <ctime>
#include<iomanip>
#include <vector>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <limits>
#include <stdint.h>
#include <omp.h>

#include "VERSION"

#define ERROR_OUT string ( __FILE__ ) +  ":" + to_string( (uint) __LINE__) + ":" + string (__FUNCTION__)

//external libs

using namespace std;

#ifdef COMPILE_FOR_MAC  
#define SHM_NORESERVWE 010000
#endif

typedef int8_t int8;
typedef uint8_t uint8;

#define uint unsigned long long
#define sint signed long long
#define uint64 unsigned long long
#define uint32 unsigned int
#define uint16 unsigned short int
#define uchar unsigned char
#define int64 long long
#define int32 int

//gcc extension to be redefined for other compilers
#define uint128 __uint128_t

#define GENOME_spacingChar 5

#define uintWinBin unsigned short
#define uintWinBinMax numeric_limits<uint16>::max()

#define intSWscore int
#define intScore int

#define scoreMatch 1

//cleaned
//output
#define FERMIONoutput_oneAlignMaxBytes 100000

//SAM attr
#define ATTR_NH 1
#define ATTR_HI 2
#define ATTR_AS 3
#define ATTR_NM 4
#define ATTR_MD 5
#define ATTR_nM 6
#define ATTR_jM 7
#define ATTR_jI 8
#define ATTR_XS 9
#define ATTR_RG 10
#define ATTR_vG 11
