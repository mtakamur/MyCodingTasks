#include "TaskSortAnalysis.h"
#include "Config.h"

void SortAnalysis()
{
    gStyle->SetOptStat(0);

    /* For Bubble sort */
    TH2D *HBubble = new TH2D("HBubble", ";Number of elements;Process time [#mus]",101, 0, 1010, 150, 0, 1500);
    TProfile *pBubble;
    TF1 *fBubble = new TF1("fBubble", "[0] + x*[1] + pow(x, 2)*[2]");
    TaskSortAnalysis *Bubble = new TaskSortAnalysis("Bubble.root");
    for(int jentry=0; jentry<Bubble->nevents; jentry++)
    {
        Bubble->GetEntry(jentry);
        HBubble->Fill(Bubble->nelements, Bubble->ptime - Bubble->rtime);
    }
    pBubble = (TProfile*)(HBubble->ProfileX());
    TCanvas *cBubble = new TCanvas("cBubble", "cBubble", 1000, 800);
    TCanvas *cBubbleProfile = new TCanvas("cBubbleProfile", "cBubbleProfile", 1000, 800);

    TLatex *texBubble = new TLatex();

    cBubble->cd();
    HBubble->Draw("colz");
    HBubble->Fit(fBubble);
    texBubble->DrawLatexNDC(0.15, 0.8, "Bubble sort");
    texBubble->DrawLatexNDC(0.15, 0.75, "Fit: [0] + x*[1] + x^{2}*[2]");

    cBubbleProfile->cd();
    pBubble->Draw();

    cBubble->Print("cBubble.png");

    /* For Bucket sort */
    TaskSortAnalysis *Bucket = new TaskSortAnalysis("Bucket.root");
    TH2D *HBucket = new TH2D("hBucket", ";Number of elements;Process time [#mus]", 250, 0, 5000, 50, 0, 50);
    TH2D *HBucket2 = new TH2D("hBucket2", ";Random time [#mus];Process time [#mus]", 50, 0, 50, 50, 0, 50);
    TProfile *pBucket;
    TF1 *fBucket = new TF1("fBucket", "[0] + x*[1]");
    for(int jentry=0; jentry<Bucket->nevents; jentry++)
    {
        Bucket->GetEntry(jentry);
        //HBucket->Fill(Bucket->nelements, Bucket->ptime - Bucket->rtime);
        HBucket->Fill(Bucket->nelements, Bucket->ptime);
        HBucket2->Fill(Bucket->rtime, Bucket->ptime);
    }
    pBucket = (TProfile*)(HBucket->ProfileX());
    TCanvas *cBucket = new TCanvas("cBucket", "cBucket", 1000, 800);
    TLatex *texBucket = new TLatex();
    cBucket->SetLogz();
    HBucket->Draw("colz");
    texBucket->DrawLatexNDC(0.15, 0.8, "Bucket sort");
    texBucket->DrawLatexNDC(0.15, 0.75, "Fit: [0] + x*[1]");
    HBucket->Fit(fBucket);
    cBucket->Print("cBucket.png");

    /* For Quick sort */
    TaskSortAnalysis *Quick = new TaskSortAnalysis("Quick.root");
    TH2D *HQuick = new TH2D("hQuick", ";Number of elements;Process time [#mus]", 1000, 0, 10000, 500, 0, 500);
    TH2D *HQuick2 = new TH2D("hQuick2", ";Random time [#mus];Process time [#mus]", 50, 0, 50, 50, 0, 50);
    TF1 *fQuick = new TF1("fQuick", "[0] + x*[1]");
    TProfile *pQuick;
    for(int jentry=0; jentry<Quick->nevents; jentry++)
    {
        Quick->GetEntry(jentry);
        //HQuick->Fill(Quick->nelements, Quick->ptime - Quick->rtime);
        HQuick->Fill(Quick->nelements, Quick->ptime);
        HQuick2->Fill(Quick->rtime, Quick->ptime);
    }
    pQuick = (TProfile*)(HQuick->ProfileX());
    TCanvas *cQuick = new TCanvas("cQuick", "cQuick", 1000, 800);
    TLatex *texQuick = new TLatex();
    cQuick->SetLogz();
    HQuick->Draw("colz");
    texQuick->DrawLatexNDC(0.15, 0.8, "Quick sort");
    texQuick->DrawLatexNDC(0.15, 0.75, "Fit: [0] + x*[1]");
    HQuick->Fit(fQuick);
    cQuick->Print("cQuick.png");

    /* Drow profiling */
    TCanvas *cProfile = new TCanvas("cProfile", "cProfile", 1000, 800);
    //TProfile *pdummy = new TProfile();
    //pdummy->SetTitle(";Number of elements;Process time [#mus]");
    //pdummy->GetYaxis()->SetRangeUser(0, 1000);
    //pdummy->GetXaxis()->SetRangeUser(0, 1000);
    //pdummy->SetLineColor(kWhite);

    TLegend *legProfile = new TLegend(0.15, 0.65, 0.35, 0.85);
    legProfile->SetBorderSize(0);
    legProfile->AddEntry(pBubble, "Bubble sort");
    legProfile->AddEntry(pQuick, "Quick sort");
    legProfile->AddEntry(pBucket, "Bucket sort");

    pBubble->SetTitle(";Number of elements; Process time [#mus]");
    pBubble->GetXaxis()->SetRangeUser(0, 400);
    pBubble->GetYaxis()->SetRangeUser(0, 150);

    pBubble->SetMarkerStyle(34);
    pBubble->SetMarkerSize(0.5);
    pBubble->SetMarkerColor(kRed);
    pBubble->SetLineColor(kRed);

    pBucket->SetMarkerStyle(34);
    pBucket->SetMarkerSize(0.5);
    pBucket->SetMarkerColor(kBlue);
    pBucket->SetLineColor(kBlue);

    pQuick->SetMarkerStyle(34);
    pQuick->SetMarkerSize(0.5);
    pQuick->SetMarkerColor(kOrange-3);
    pQuick->SetLineColor(kOrange-3);

    cProfile->cd();
    //pdummy->Draw();
    pBubble->Draw("");
    pBucket->Draw("SAME");
    pQuick->Draw("SAME");
    legProfile->Draw();
    cProfile->Print("cProfile.png");

    return;
}