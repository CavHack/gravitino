#ifndef GENOME_QUEUE_H_
#define GENOME_QUEUE_H_

#include "HashChain.h"
#include "Params.h"
#include "GraviTree.h"
#include "Chaos.h"

class GenomeQueue {

 public:
  char *GenomeQueue, *signatureGenome;
  GraviTree SA, SAinsert, SApass1, SApass2;
  GraviTree SAi;
  Variation *Var;

  uint nGenomeStackInsert, nGenomeStackPass1, nGenomeStackPass2, nSAinsert, nsApass1, nsApass2;

  ParamsGenome &pGe;

  //ch parameters
  vector <uint> chrStart, chrLength, chrLenghtAll;
  uint genomeChrBinbases, chrBinN, *chrBin;
  vector <string> chrName, chrNameAll;

  uint LmerIndxStart; //begin L-mer dimer sequence
  
  //Genomic stack
  //genome length, SA lenght, # of chromosomes
  uint nGenomeStack, nSAbytes, nChrReal;




}
