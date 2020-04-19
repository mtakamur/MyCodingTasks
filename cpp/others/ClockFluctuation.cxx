#include <iostream>
#include <ctime>
#include <random>
#include <TFile.h>
#include <TTree.h>

int GetRandom(int n_random);

int main()
{

    double clock1, clock2, clock3;
    TFile *file = new TFile("ClockFluctuation.root", "recreate");
    TTree *tree = new TTree("tree", "tree");
    tree->Branch("clock1", &clock1, "clock1/D");
    tree->Branch("clock2", &clock2, "clock2/D");
    tree->Branch("clock3", &clock3, "clock3/D");


    //for(int i=0; i<10000000; i++)
    for(int i=0; i<10000; i++)
    {
        clock1 = (double)clock();
        GetRandom(1000);
        clock2 = (double)clock();
        GetRandom(1000);
        clock3 = (double)clock();
        tree->Fill();
    }

    file->cd();
    tree->Write();
    file->Close();
    return 0;
}

int GetRandom(int n_random)
{
    std::random_device rnd;
    std::mt19937 mt(rnd());
    for(int i=0; i<n_random; i++)
    {
        std::cout << mt();
    }
    return 0;
}