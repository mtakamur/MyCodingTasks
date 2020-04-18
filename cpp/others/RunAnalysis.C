#include "AnalysisTaskClockFluctuation.h"
#include <TFile.h>
#include <TTree.h>
#include <TString.h>

void RunAnalysis()
{
    AnalysisTaskClockFluctuation *task = new AnalysisTaskClockFluctuation("ClockFluctuation.root");

    TH1D *hclock12 = new TH1D("hclock12", "hclock12", 100, 0, 100);
    TH1D *hclock23 = new TH1D("hclock23", "hclock23", 100, 0, 100);
    TH1D *hclock31 = new TH1D("hclock31", "hclock31", 100, 0, 100);

    for(int jentry=0; jentry<task->nentries; jentry++)
    {
        task->GetEntry(jentry);
        double dif12 = task->clock1-task->clock2;
        double dif23 = task->clock2-task->clock3;
        double dif31 = task->clock3-task->clock1;

        hclock12->Fill(dif12);
        hclock23->Fill(dif23);
        hclock31->Fill(dif31);
    }
    TCanvas *cDiff = new TCanvas("cDiff", "cDiff", 600, 200);
    cDiff->Divide(3, 1);

    cDiff->cd(1);
    hclock12->Draw();
    cDiff->cd(2);
    hclock23->Draw();
    cDiff->cd(3);
    hclock31->Draw();
    return;
}