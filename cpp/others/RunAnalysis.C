#include "AnalysisTaskClockFluctuation.h"
#include <iostream>
#include <cmath>
#include <TFile.h>
#include <TTree.h>
#include <TF1.h>
#include <TString.h>

void RunAnalysis()
{
    gStyle->SetOptStat(0);
    AnalysisTaskClockFluctuation *task = new AnalysisTaskClockFluctuation("ClockFluctuation.root");

    TF1 *fclock12 = new TF1("fclock12", "gaus");
    TF1 *fclock23 = new TF1("fclock23", "gaus");
    TF1 *fclock31 = new TF1("fclock31", "gaus");

    double s12, e12;
    double s23, e23;
    double s31, e31;

    double s1, s2, s3;// Individual timing resolution
    double e1, e2, e3;// Individual error of timing resolution

    TH1D *hclock12 = new TH1D("hclock12", "hclock12", 150, -200, -50);
    TH1D *hclock23 = new TH1D("hclock23", "hclock23", 150, -200, -50);
    TH1D *hclock31 = new TH1D("hclock31", "hclock31", 300, 150, 450);

    TH2D *Hdif1223 = new TH2D("Hdif1223", "Hdif1223", 110, -200, -90, 100, -200, -100);
    TH2D *Hdif2331 = new TH2D("Hdif2331", "Hdif2331", 110, -200, -90, 250, 200, 450);
    TH2D *Hdif3112 = new TH2D("Hdif3112", "Hdif3112", 250, 200, 450, 110, -200, -90);

    for(int jentry=0; jentry<task->nentries/10; jentry++)
    {
        task->GetEntry(jentry);
        double dif12 = task->clock1-task->clock2;
        double dif23 = task->clock2-task->clock3;
        double dif31 = task->clock3-task->clock1;

        hclock12->Fill(dif12);
        hclock23->Fill(dif23);
        hclock31->Fill(dif31);

        Hdif1223->Fill(dif12, dif23);
        Hdif2331->Fill(dif23, dif31);
        Hdif3112->Fill(dif31, dif12);
    }
    TCanvas *cDiff = new TCanvas("cDiff", "cDiff", 1000, 500);
    cDiff->Divide(3, 1);
    cDiff->cd(1);
    hclock12->Draw();
    hclock12->Fit(fclock12, "", "", -115, -90);
    cDiff->cd(2);
    hclock23->Draw();
    hclock23->Fit(fclock23, "", "", -115, -90);
    cDiff->cd(3);
    hclock31->Draw();
    hclock31->Fit(fclock31, "", "", 190, 225);

    TCanvas *cDiffCorr = new TCanvas("cDiffCorr", "cDiffCorr", 1000, 600);
    cDiffCorr->Divide(3, 1);
    cDiffCorr->cd(1);
    Hdif1223->Draw("colz");
    cDiffCorr->cd(2);
    Hdif2331->Draw("colz");
    cDiffCorr->cd(3);
    Hdif3112->Draw("colz");

    s12 = fclock12->GetParameter(2);
    s23 = fclock23->GetParameter(2);
    s31 = fclock31->GetParameter(2);
    e12 = fclock12->GetParError(2);
    e23 = fclock23->GetParError(2);
    e31 = fclock31->GetParError(2);

    s1 = sqrt( ( pow(s12,2) - pow(s23,2) + pow(s31,2) )/2 );
    s2 = sqrt( ( pow(s12,2) - pow(s31,2) + pow(s23,2) )/2 );
    s3 = sqrt( ( pow(s23,2) - pow(s12,2) + pow(s31,2) )/2 );

    std::cout << "s1 = " << s1 << std::endl;
    std::cout << "s2 = " << s2 << std::endl;
    std::cout << "s3 = " << s3 << std::endl;
    return;
}