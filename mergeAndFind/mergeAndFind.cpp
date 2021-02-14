#include<vector>
#include<iostream>

using namespace std;


int find(vector<int>&parent ,int i){
    if(parent[i] == i){
        return i;
    }
    parent[i] = find(parent, parent[i]);
    return parent[i];
}

void merge(vector<int>&parent,vector<int>&rank,int i,int j){
    int x = find(parent, i);
    int y = find(parent, j);
    if(rank[x]>rank[y]){
        parent[y] = x;
    }else{
        parent[x] = y;
    }
    if(rank[x]==rank[y]){
        rank[y]++;
    }
    return;
}

int main()
{

}