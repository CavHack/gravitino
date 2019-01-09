#include "HashChain.h"
#include "SigmaFuncts.h"
#include "Service.cpp"

HashChain::(Params &Pin, string hashChainFileNameIn) : P(Pin), hashChainFileName(chainFileNameIn) {

    hashChainLoad();


};

void HashChain::hashChainLoad() {

    ifstream &streamIn = ifstrOpen(hashChainFileName, ERROR_OUT, "SOLUTION: check path and permission for the hash chain file" + hashChainFileName, P);

    string chr1; //current chromosome 1(old)

    while (streamIn.good()) {

        string line1;
        getline(streamIn, line1);
        istringstream line1str(line1);

        vector<string> fields(13);

        for (int ii=0; ii<4;ii++)
            line1str >> fields[ii];
            if (fields[0]=="")
            {
                //empty line, continue

            }else if (fields[1]=="")
            {
                //end of hash chain
                chrChains[chr1].bLen.push_back(std::stoi(fields[0]));
                chrChains[chr1].bN = chrChains[chr1].bLen.size();
            } else if (fields[3]=="") {
                //normal hash chain block
                chrChains[chr1].bLen.push_back(std::stoi(fields[0]));

                uint s=chrChains[chr1].bStart1.back() + chrChains[chr1].bLen.back() + std::stoi(fields[1]); //prev start + length +shift
            }
    }

}