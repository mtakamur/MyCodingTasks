#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N, W;
    vector<vector<int>> Item;
    vector<vector<int>> DP;

    cin >> N >> W;

    Item.resize(N);
    DP.resize(N);

    for(int i=0; i<N; i++)
    {
        Item.at(i).resize(2);
        DP.at(i).resize(W);
        cin >> Item.at(i).at(0) >> Item.at(i).at(1);

        for (int sum_w = 0; sum_w < W; sum_w++)
        {// Initialize DP table with 0
            DP.at(i).at(sum_w) = 0;
        }
    }

    for(int inode=0; inode<N; inode++)
    {
        for(int wnode=0; wnode<W; wnode++)
        {
        }
    }
    return 0;
}