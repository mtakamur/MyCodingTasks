#include <iostream>
#include <ctime>
#include <time.h>
#include <TFile.h>
#include <TTree.h>

int main()
{
    double clock1, clock2, clock3;
    TFile *file = new TFile("ClockFluctuation.root", "recreate");
    TTree *tree = new TTree("tree", "tree");
    tree->Branch("clock1", &clock1, "clock1/D");
    tree->Branch("clock2", &clock2, "clock2/D");
    tree->Branch("clock3", &clock3, "clock3/D");

    for(int i=0; i<10000000; i++)
    {
        clock1 = (double)clock();
        clock2 = (double)clock();
        clock3 = (double)clock();
        tree->Fill();
    }

    file->cd();
    tree->Write();
    file->Close();
    return 0;
}