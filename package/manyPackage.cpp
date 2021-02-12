#include<iostream>
#include<vector>

using namespace std;

int manyPackage(vector<int>&value,vector<int>&cost,int v){
    vector<int> dp(v + 1, 0);
    int n = cost.size();
    for (int i = 0; i < n;i++){
        for (int j = cost[i]; j < v + 1;j++){
            dp[j] = max(dp[j], dp[j - cost[i]] + value[i]);
        }
    }
    return dp[v];
}
