#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
    int N;
    vector<int> h;// List of height
    vector<int> DP;// Hold DP value for each node

    cin >> N;

    h.resize(N);
    DP.resize(N);
    
    for(int i=0; i<N; i++)
    {
        cin >> h.at(i);
    }

    /////////////////////////
    // Initialize DP table //
    /////////////////////////
    DP.at(0) = 0;
    DP.at(1) = abs(h.at(0) - h.at(1));

    ////////////////////////////////////
    // Fill DP table to the last node //
    ////////////////////////////////////
    for(int inode=2; inode<N; inode++)
    {
        int dp1, dp2;
        dp1 = abs(h.at(inode-2) - h.at(inode)) + DP.at(inode-2);
        dp2 = abs(h.at(inode-1) - h.at(inode)) + DP.at(inode-1);
        DP.at(inode) = min(dp1, dp2);
    }

    cout << DP.at(N-1) << endl;
    return 0;
}