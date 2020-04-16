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

    int r[1000000];// Elements container

    TFile *file = new TFile("Bucket.root", "recreate");
    TTree *tree = new TTree("tree", "tree");
    tree->Branch("rtime", &rtime, "rtime/D");
    tree->Branch("ptime", &ptime, "ptime/D");
    tree->Branch("nelements", &nelements, "nelements/I");

    EventGenerator ev(0, 100, NMIN);

    for(nelements=NMIN; nelements<=NMAX; nelements+=NSTEP)
    {
        for(int i=0; i<NEVENT; i++)
        {
            int b[101][5000];  // Bucket for sort
            int bcounter[5000]; // Elements counter for each bucket
            int ecounter = 0;      // Elements counter for taking out from the bucket
            int position = 0;
            for (int j = 0; j < 5000; j++)
            { // Initialize every counter with 0
                bcounter[j] = 0;
            }

            ev.SetNelements(nelements);
            ev.GenerateElements(r);
            rtime = ev.GetTime();
            pstart = clock();
            /* Sort process start */

            for(int j=0; j<nelements; j++)
            {// Throw all the elements into the bucket
                //std::cout << r[j] << " ";
                b[r[j]][bcounter[r[j]]] = r[j];
                bcounter[r[j]]++;
            }
            //std::cout << std::endl;
            while(ecounter < nelements)
            {// Take out elements one by one
                bcounter[position]--;
                while(bcounter[position] < 0)
                {
                    position++;
                    bcounter[position]--;
                }
                r[ecounter] = b[position][bcounter[position]];
                //std::cout << r[ecounter] << " ";
                ecounter++;
            }
            //std::cout << std::endl;
            /* Sort process finish */
            pfinish = clock();
            ptime = (double)(pfinish - pstart);
            tree->Fill();
        }
    }
    file->cd();
    tree->Write();
    file->Close();
    return 0;
}