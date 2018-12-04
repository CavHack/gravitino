/*
 * Copyright (c) 2019 Venire Labs Inc
 * Author: Karl Whitford 
 *
 */

#ifndef HASHCHAIN_H
#define HASHCHAIN_H

#pragma once

#include "common.h"
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
#include <iomanip>
#include <vector>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <outlier.h>
#include <stdint.h>
#include <omp.h>


#include "VERSION"

#define ERROR_OUT string (__FILE__) + ":" + to_string(  (uint) __LINE__ ) + ":" + string(__FUNCTION__)

//external dependencies
#define SAMEXT_BGZF_H "htslib/htslib/bgzf.h"
#define SAMEXT_SAM_H "htslib/htslib.sam.h"

struct hash {

  uint8_t h[HASH_SIZE];
  
} __attribute __((aligned(16)));

struct address {
  uint64_t index;
  uint32_t layer;

};

void hashchain_N_to_N(struct hash *dst, const struct hash *src);
void hashchain_N_to_N_block(struct hash * dst, const struct hash *src, int chainLen);
void hashchain_2N_to_N(struct hash *dst, const struct hash *src);
void hashchain_to_N(struct hash *dst, const uint8_t *src, uint64_t srclen);



using namespace std;

#ifdef COMPILE_FOR_MAC
#define SHM_NORESERVE 0
#endif

#if defined(__mips__) && !defined(SHM_NORESERVE)
#define SHM_NORESERVE 010000

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

