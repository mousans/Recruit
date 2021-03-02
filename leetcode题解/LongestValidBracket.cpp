#include<iostream>
#include<vector>
#include<string>

using namespace std;

/**
 * 算法思想:对于第i个位置来说,如果为'('则其有效长度一定为0，所以只讨论')'
 * dp[i]数组的含义是以第i位结尾的长度
 * 当s[i-1] ='（'则dp[i] = 2+dp[i-2];
 * 当是s[i-1]=')'则讨论i-dp[i-1]-1处的元素,如果为')'则dp[i]=0，如果为'('则dp[i]=2+dp[i-1]+dp[i-dp[i-1]-2]
 * */
int longestValidParentheses(string s) {
    vector<int> dp(s.length(), 0);
    int res = 0;
    for (int i = 1; i < s.length();i++){
        if(s[i] == ')'){
            if(s[i-1] == '('){
                if(i>1){
                    dp[i] = dp[i - 2] + 2;
                }else{
                    dp[i] = 2;
                }
            }else if(i-dp[i-1]-1>-1 &&s[i-dp[i-1]-1] == '('){
                if(i - dp[i - 1] - 2>-1)
                    dp[i] = 2 + dp[i - 1] + dp[i - dp[i - 1] - 2];
                else{
                    dp[i] = 2 + dp[i - 1];
                }
            }
            res = max(res, dp[i]);
        }
    }
    return res;
}

int main(){

}