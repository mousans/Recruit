#include<iostream>
#include<vector>

using namespace std;

int muchPackage(vector<int>cost,vector<int>value,vector<int>nums,int v){
    int n = cost.size();
    vector<int> dp(v + 1, 0);
    for (int i = 0; i < n;i++){
        for (int j = cost[i]; j < v + 1;j++){
            for (int t = 1; t < nums[i]&&t*cost[i]<j+1;t++){
                dp[j] = max(dp[j], dp[j - t * cost[i]] + t * value[i]);
            }
        }
    }
    return dp[v];
}

int main()
{

}