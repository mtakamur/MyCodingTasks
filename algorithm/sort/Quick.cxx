#include <iostream>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <TFile.h>
#include <TTree.h>
#include "Config.h"
#include "EventGenerator.h"

int CheckFullDuplication(int t[], int l, int m);
int Scan(int t[], int l, int m, int s);
int Rescan(int t[], int l, int m);

int main()
{
    double rtime = 0;
    double ptime = 0;
    int nelements = 0;

    clock_t pstart = 0;
    clock_t pfinish = 0;

    int r[10000];// Elements container
    int a[10] = {1, 2, 23, 2, 5, 12, 11, 0, 0, 0};

    TFile *file = new TFile("Quick.root", "recreate");
    TTree *tree = new TTree("tree", "tree");
    tree->Branch("rtime", &rtime, "rtime/D");
    tree->Branch("ptime", &ptime, "ptime/D");
    tree->Branch("nelements", &nelements, "nelements/I");

    EventGenerator ev(0, 100, NMIN);

    for(nelements=NMIN; nelements<=NMAX; nelements+=NSTEP)
    {
        for(int i=0; i<NEVENT; i++)
        {
            ev.SetNelements(nelements);
            ev.GenerateElements(r);
            rtime = ev.GetTime();
            /* Sort process start */
            pstart = clock();
            Rescan(r, 0, nelements-1);
            /* Sort process finish */
            pfinish = clock();
            ptime = (double)(pfinish - pstart);
            tree->Fill();
        }
    }

    file->cd();
    tree->Write();
    file->Close();
    return 0;
}

int Scan(int t[], int l, int m, int s)
{
    // m: Left edge of vector
    // l: Right edge of vector
    int i=l, j=m;
    int base = s;
    while(l <= m)
    {
        while((l<=j) && (t[l]<base)) l++;
        while((i<=m) && (t[m]>=base)) m--;
        if(m<l)
        {
           break;
        }
        else
        {
            std::swap(t[l], t[m]);
            //std::cout << "Swapped" << std::endl;
            l++; m--;
        }
    }
    return l;
}

int CheckFullDuplication(int t[], int l, int m)
{
    int k = l+1;
    while(k<=m && t[l] == t[k]) k++;
    if(k>m) return -1;
    if(t[l] >= t[k]) return l;
    return k;
}

int Rescan(int t[], int l, int m)
{
    if(l == m) return 0;
    int s = CheckFullDuplication(t, l, m);
    //std::cout << s << std::endl;
    if(s != -1)
    {
        int n = Scan(t, l, m, t[s]);
        //std::cout << n << std::endl;
        Rescan(t, l, n-1);
        Rescan(t, n, m);
    }
    return 0;
}