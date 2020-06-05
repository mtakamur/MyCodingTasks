#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int GetMax(vector<int> source){
    int max = source.at(0);
    for(int i=1; i<source.size(); i++)
    {
        if(source.at(i) > max) max = source.at(i);
    }
    return max;
}

int main()
{
    int nvacation;
    vector<vector<int>> DP;
    vector<vector<int>> Act;

    cin >> nvacation;

    DP.resize(nvacation);
    Act.resize(nvacation);

    for(int i=0; i<nvacation; i++)
    {
        DP.at(i).resize(3);
        Act.at(i).resize(3);
        cin >> Act.at(i).at(0) >> Act.at(i).at(1) >> Act.at(i).at(2);
    }

    DP.at(0).at(0) = Act.at(0).at(0);
    DP.at(0).at(1) = Act.at(0).at(1);
    DP.at(0).at(2) = Act.at(0).at(2);

    for(int inode=1; inode<nvacation; inode++)
    {
        int dp01, dp02;// Transition from Act0
        int dp10, dp12;// Transition from Act1
        int dp20, dp21;// Transition from Act2

        dp01 = DP.at(inode-1).at(0) + Act.at(inode).at(1);
        dp02 = DP.at(inode-1).at(0) + Act.at(inode).at(2);
        dp10 = DP.at(inode-1).at(1) + Act.at(inode).at(0);
        dp12 = DP.at(inode-1).at(1) + Act.at(inode).at(2);
        dp20 = DP.at(inode-1).at(2) + Act.at(inode).at(0);
        dp21 = DP.at(inode-1).at(2) + Act.at(inode).at(1);

        DP.at(inode).at(0) = max(dp10, dp20);
        DP.at(inode).at(1) = max(dp01, dp21);
        DP.at(inode).at(2) = max(dp02, dp12);
    }

    cout << GetMax(DP.at(nvacation-1)) << endl;
    
    return 0;
}