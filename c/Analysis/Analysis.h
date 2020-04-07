#ifndef Analysis_H
#define Analysis_H

#include <iostream>
#include <TFile.h>
#include <TTree.h>
#include <TH1D.h>
#include <TCanvas.h>

class Analysis
{
    private:
        TString name = "";
        TFile *fdata = 0x0;
        TTree *tree = 0x0;
        long nentries = 0;// number of entries
        Double_t time = 0;// Data container

    public:
        TH1D *htime = 0x0;

        Analysis(TString file_name);
        ~Analysis();
};

Analysis::Analysis(TString file_name)
{
    name = file_name;
    fdata = new TFile(Form("%s.root",name.Data()), "read");
    if(fdata)
    {
        tree = (TTree*)(fdata->Get("tree"));
        if(tree)
        {
            tree->SetBranchAddress("time", &time);
        }
    }

    ///////////////////
    // Analysis part //
    ///////////////////
    nentries = tree->GetEntriesFast();// Get number of entries
    htime = new TH1D("htime", "htime", 100, 0, 1.0);

    for(Int_t jentry=0; jentry<nentries; jentry++)
    {
        tree->GetEntry(jentry);
        htime->Fill(time);
    }
}

Analysis::~Analysis()
{
}
#endif