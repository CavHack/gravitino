#ifndef __SolitonAlign_H__
#define __SolitonAlign_H__

#include "common.h"
#include "Params.h"
#include "TranscriptomeMeta.h"
#include "SolitonSegment.h"
#include "GenomeQueue.h"

#include <memory>

class RA;

class SolitonAlign {

    public:
        SolitonSegment seg1, seg2; //two chimeric solitonic segments
        // std::unique_ptr<TranscriptomeMeta> al1, al2; // chimeric soliton switching
        TranscriptomeMeta *al1, *al2;
        uint ex1, ex2;

        uint chimJ1, chimJ2, chimRepeat1, chimRepeat2;
        int chiMotif, chimStr, chimScore;

        SolitonAlign(SolitonSegment &seg1in, SolitonSegment &seg2in, int chimScoreIn, GenomeQueue &genomeIn, RA *RAin); //allocate
        void solitonJunctionOutput(fstream &outstream, uint chimN);
        void solitonStitching(char* genSeq, char *readSeq);
        bool solitonCheck();

        bool stitchingDone;

        private:
            Params &P;
            ParamsChimeric &pCh;
            GenomeQueue &mapGen;
            RA *RA;


};

#endif