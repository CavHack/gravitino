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
  uint nGenomeStack2, nSA2, nSAbyte2, nChrReal2; 
  uint nSAi; // SA index.

  unsigned char GrstrandBit, SAiMarkNbit, SAiMarkAbsentBit; //SA index bit for strand information
  uint GstrandMask, SAiMarkAbsentMask, SAiMarkAbsentMaskC, SAiMarkNmask, SAiMarkNmaskC; //remove strand bit from index.

  //SJ database parameters
  uint spliceJDBOverhang, spliceJDBLength; //length of the donor/acceptor, lenght of the splice junction "chromosome" = 2 * 
  uint spliceJChrStart, spliceJDBN; //first sj-db chr
  uint spliceJGstart; // start of the sj-db genome sequence
  uint *spliceJDstart, *spliceJAstart, *spliceJDBStart, *spliceJDBEnd; //sjdb loci
  uint8 *spliceJDBMotif; //motifs of annotated junctions
  uint8 *spliceJDBShiftLeft, *spliceJDBShiftRight; //shift of junctions
  uint8 *spliceJDBStrand; // Junctions strand, not used yet.

  //sequence insert parameters
  uint genomeInsertL; //total length of the sequence to be intserted on the fly.
  uint genomeInsertChrIndFirst; //index of the first inserted chromosome.

  sharedMemory * sharedMemory;

  GenomeQueue (Params &Pin);
  //~GenomeQueue();

  void freeMemory();
  void genomeLoad();
  void chrBinFill();
  void chrInfoLoad();

  void insertSequences();
  void genomeGenerate();

  private:
    Params &P;
    key_t shmKey;
    char *shmStart;
    char *G1;
    uint OpenSink(string name, ifstream & sink, uint size);
    void HandleSharedMemoryExceptions(const SharedMemoryException & exc, uint64 shmSize);


};

#endif
