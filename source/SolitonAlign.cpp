#include "SolitonAlign.h"

SolitonAlign::SolitonAlign(SolitonSegment &seg1in, SolitonSegment &seg2in, int chimScoreIn, GenomeQueue &genomeIn, RA *RAin) 
    : seg1(seg1in), seg2(seg2in), chimScore(chimScoreIn), P(seg1in.P), pCh(P.pCh), mapGen(genomeIn), RA(RAin) {
        stitchingDone = false;

        al1=&seg1.align;
        al2=&seg2.align;

        if (al1->roStart > al2->roStart)
            swap(al1, al2);

            ex1 = al1->Str== 1 ? 0 : al1->nExons-1;
            ex2 = al2->Str== 0 ? 0 : al2->nExons-1;

            bool SolitonAlign::solitonCheck() {
                chimGood = chimGood && al1->exons[ex1][EX_iFrag] <= al2.exons[ex2][EX_iFrag]; // otherwise - strange configuration, both segments contain two mates

             chimGood = chimGood && (al1->exons[ex1][EX_iFrag] < al2->exons[ex2][EX_iFrag] || (al1->exons[ex1][EX_L] >= pCh.junctionOverhangMin &&  al2->exons[ex2][EX_L] >= pCh.junctionOverhangMin) );

    return chimGood;


    };