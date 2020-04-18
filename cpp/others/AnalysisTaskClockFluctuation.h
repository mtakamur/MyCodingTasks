#ifndef AnalysisTaskClockFluctuation_H
#define AnalysisTaskClockFluctuation_H

class TFile;
class TTree;
class TString;

class AnalysisTaskClockFluctuation
{
    public:
        int nentries;
        TFile *file;
        TTree *tree;
        double clock1, clock2, clock3;

        AnalysisTaskClockFluctuation(TString file_name);
        ~AnalysisTaskClockFluctuation();
        void GetEntry(int entry);
};

AnalysisTaskClockFluctuation::AnalysisTaskClockFluctuation(TString file_name)
{
    file = new TFile(Form("%s", file_name.Data()), "read");
    if(file)
    {
        tree = (TTree*)(file->Get("tree"));
        if(tree)
        {
            tree->SetBranchAddress("clock1", &clock1);
            tree->SetBranchAddress("clock2", &clock2);
            tree->SetBranchAddress("clock3", &clock3);
            nentries = tree->GetEntriesFast();
        }
    }
}

AnalysisTaskClockFluctuation::~AnalysisTaskClockFluctuation()
{}

void AnalysisTaskClockFluctuation::GetEntry(int entry)
{
    tree->GetEntry(entry);
    return;
}
#endif