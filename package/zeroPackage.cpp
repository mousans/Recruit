#include<iostream>
#include<vector>

using namespace std;

/*
01背包,最外层对物品种类进行循环，内层由于物品只能拿一次，所以体积从大往小循环，得到结果，且初始化(没有物品的时候)dp数组的值全为零
*/

int zeroPackage(vector<int>value,vector<int>cost,int v){
    int n=value.size();
    vector<int>dp(v+1,0);
    for(int i=0;i<n;i++){
        for(int j=v;i>cost[i]-1;i--){
            dp[j]=max(dp[j],dp[j-cost[i]]+value[i]);
        }
    }
    return dp[v+1];
}

int main()
{
    
}