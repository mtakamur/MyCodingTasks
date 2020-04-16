#include <iostream>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <TFile.h>
#include <TTree.h>
#include "Config.h"
#include "EventGenerator.h"

int main()
{
    double rtime = 0;
    double ptime = 0;
    int nelements = 0;

    clock_t pstart = 0;
    clock_t pfinish = 0;

    int r[1000000];

    TFile *file = new TFile("Bubble.root", "recreate");
    TTree *tree = new TTree("tree", "tree");
    tree->Branch("rtime", &rtime, "rtime/D");
    tree->Branch("ptime", &ptime, "ptime/D");
    tree->Branch("nelements", &nelements, "nelements/I");

    EventGenerator ev(0, 100, NMIN);

    for(nelements=NMIN; nelements<=NMAX; nelements+=NSTEP)
    {
        for(int i=0; i<NEVENT; i++)
        {// Sort algorithm starts here
            ev.SetNelements(nelements);
            ev.GenerateElements(r);
            rtime = ev.GetTime();
            pstart = clock();
            for(int j=0; j<nelements; j++)
            {
                for(int k=0; k<nelements-j; k++)
                {
                    if(r[k] < r[k+1])
                    {
                        std::swap(r[k], r[k+1]);
                    }
                }
            }
            //for(int j=0; j<nelements; j++)
            //{
            //    std::cout << r[j] << " ";
            //}
            //std::cout << std::endl;
            pfinish = clock();
            ptime = (double)(pfinish - pstart);
            //std::cout << ptime << " ";
            tree->Fill();
        }
    }
    file->cd();
    tree->Write();
    file->Close();
    return 0;
}