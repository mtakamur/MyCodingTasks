#ifndef MakeRoot_H
#define MakeRoot_H

#include <iostream>
#include <sstream>
#include <TFile.h>
#include <TTree.h>
#include <TString.h>

class MakeRoot
{
    private:
        TFile *foutput = 0x0;
        TTree *tree = 0x0;
        std::ifstream *finput = 0x0;
        bool FILE_OPENED = false;
        bool SUCCESS = false;
        TString name = "";

        Double_t value = 0;// temporary data container

    public:
        MakeRoot(TString file_name);
        ~MakeRoot();
        bool GenerateData();
};

MakeRoot::MakeRoot(TString file_name)
{
    finput = new std::ifstream(Form("%s.dat",file_name.Data()));
    if(finput)
    {
        name = file_name;
        FILE_OPENED = true;
        std::cout << "File" << file_name.Data() << "opened." << std::endl;
        GenerateData();
    }
    else
    {
        std::cout << "Error on file opening." << std::endl;
    }
}

MakeRoot::~MakeRoot()
{
}

bool MakeRoot::GenerateData()
{
    if(FILE_OPENED)
    {
        foutput = new TFile(Form("%s.root",name.Data()), "recreate");
        tree = new TTree("tree", "tree");
        tree->Branch("time", &value, "time/D");

        while(*finput >> value)
        {
            tree->Fill();
        }
        foutput->cd();
        tree->Write();
        foutput->Close();
        SUCCESS = true;
    }
    else
    {
        std::cout << "No raw file opened." << std::endl;
        SUCCESS = false;
    }
    
    return SUCCESS;
}
#endif