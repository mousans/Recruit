#include<iostream>
#include<vector>

using namespace std;

//弗洛伊德算法其核心是map[i][j] = min(maps[i][k]+mpa[k][j],map[i][j]);


vector<vector<int>> floyd(vector<vector<int>>mps){
    int n = mps.size();
    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if(mps[i][k]!=INT_MAX && mps[k][j]!=INT_MAX){
                    mps[i][j] = min(mps[i][j], mps[i][k] + mps[k][j]);
                }
            }
        }
    }
    return mps;
}

int main()
{

}