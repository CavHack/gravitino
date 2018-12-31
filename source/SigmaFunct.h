#ifndef __SIGMAFUNCT_H__
#define __SIGMAFUNCT_H__

#include "common.h"

void complementSeqNumbers(char *, char *, uint);
void convertNucleotidesToNumbers(const char * R0, char* R1, const uint Lread);
uint convertNucleotidesToNumbersRemoveControls(cons char * R0, char *R1, const uint Lread);
void revComplementNucleotides(string &seq);
char nuclToNumBAM(char cc);
void nuclPackBAM(char* ReadsIn, char* ReadsOut, uint Lread);
char convertNt01234(const char R0); // transform sequence from ACGT into 0-1-2-3-4 code

uint chrFind(uint, uint, uint*); //Find chromosome from global locus
uint localSearch(const char *v, uint nx, const char *y, uint ny, double pMM);

uint qualitySplit(char*, char*, uint, char, uint, uint, uint**);

#endif
