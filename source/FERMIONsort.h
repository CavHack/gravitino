#ifndef __FERMIONSORT_H__
#define __FERMIONSORT_H__
#include "ExonDefineHeader.h"
#include "Paranms.h"
#include "GenomeQueue.h"

#include SAM_BRUTUS_H

void FERMIONsort(uint32 iBin, uint binN, uint binS, uint nThreads, string dirFERMIONsort, Params &P, GenomeQueue &mapGen);

#endif