#include "MakeRoot.h"
#include "Analysis.h"

void RunAnalysis()
{
    gStyle->SetOptStat(0);
    //MakeRoot *Function = new MakeRoot("result_function");
    //MakeRoot *Macro = new MakeRoot("result_macro");

    Analysis *Function = new Analysis("result_function");
    Analysis *Macro = new Analysis("result_macro");

    TCanvas *ctime = new TCanvas("ctime", "ctime", 1000, 700);

    TH1D *hdummy_time = new TH1D("hdummy_time", ";Time[#mus];Entries", 100, 0, 0.2);
    hdummy_time->GetYaxis()->SetRangeUser(0, 3.0e+5);
    hdummy_time->SetLineColor(kWhite);

    Function->htime->SetLineColor(kRed);
    Function->htime->SetMarkerStyle(31);
    Function->htime->SetMarkerSize(2);
    Function->htime->SetMarkerColor(kRed);
    Macro->htime->SetLineColor(kBlue);
    Macro->htime->SetMarkerStyle(31);
    Macro->htime->SetMarkerSize(2);
    Macro->htime->SetMarkerColor(kBlue);

    TLatex *textime = new TLatex();

    TLegend *legtime = new TLegend(0.7, 0.7, 0.85, 0.85);
    legtime->SetBorderSize(0);
    legtime->AddEntry(Function->htime, "Function", "l");
    legtime->AddEntry(Macro->htime, "Macro", "l");

    ctime->cd();
    hdummy_time->Draw();
    Function->htime->Draw("SAME");
    Macro->htime->Draw("SAME");
    legtime->Draw();
    return;
}