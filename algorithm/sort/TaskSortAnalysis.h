#ifndef TaskSortAnalysis_H
#define TaskSortAnalysis_H

class TaskSortAnalysis
{
    private:
        TString fname;
        TFile *file = 0x0;
        TTree *tree = 0x0;

    public:
        int nevents;
        int nelements;
        double rtime;
        double ptime;

        TaskSortAnalysis(TString file_name);
        ~TaskSortAnalysis(){};
        void GetEntry(int entry_number);
};

TaskSortAnalysis::TaskSortAnalysis(TString file_name)
{
    fname = file_name;
    file = new TFile(Form("%s",fname.Data()), "read");
    if(file)
    {
        tree = (TTree*)(file->Get("tree"));
        if(tree)
        {
            tree->SetBranchAddress("nelements", &nelements);
            tree->SetBranchAddress("rtime", &rtime);
            tree->SetBranchAddress("ptime", &ptime);

            nevents = tree->GetEntriesFast();
        }
    }
}

void TaskSortAnalysis::GetEntry(int entry_number)
{
    tree->GetEntry(entry_number);
    return;
}
#endif