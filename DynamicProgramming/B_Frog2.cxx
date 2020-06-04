#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
    int N, K;
    vector<int> h;// List of height
    vector<int> DP;// Hold DP value for each node

    cin >> N >> K;

    h.resize(N);
    DP.resize(N);
    
    for(int i=0; i<N; i++)
    {
        cin >> h.at(i);
        DP.at(i) = 10000;// Initialize all nodes with expected maximum cost + 1
    }

    /////////////////////////
    // Initialize DP table //
    /////////////////////////
    DP.at(0) = 0;

    ////////////////////////////////////
    // Fill DP table to the last node //
    ////////////////////////////////////
    for(int inode=0; inode<N; inode++)
    {
        for(int jnode=inode+1; jnode-inode<K; jnode++)
        {
            if(jnode == N-1) continue;
            cout << jnode << endl;
            int dp = abs(h.at(inode) - h.at(jnode));
            if(dp < DP.at(jnode)) DP.at(jnode) = dp;
        }
    }

    cout << DP.at(N-1) << endl;
    return 0;
}