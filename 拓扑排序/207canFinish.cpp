#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

/**
 * numCourses：一共由多少门课,课编0-numCourses-1；
 * prerequisites：前提要求,元素为一个两个课程编号的vector,vector[0]依赖vctor<1>
 * 
 * 思考:拓扑排序,每一个依赖都是被依赖节点到依赖节点的一条有向路径,维护一个入读为0的队列,每次从队列出节点,更新每个节点的入度,不断循环,直到没有入度为0的节点,或者所有节点都出完
 * */

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, int> inToNum;
    unordered_map<int, vector<int>> outToNode;
    vector<int> outNode;
    vector<int> canOutNode;
    for (int i = 0; i < prerequisites.size();i++){
        if(inToNum.find(prerequisites[i][0]) != inToNum.end()){
            inToNum[prerequisites[i][0]]++;
        }else{
            inToNum[prerequisites[i][0]] = 1;
        }   
        if(outToNode.find(prerequisites[i][1]) != outToNode.end()){
            outToNode[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }else{
            outToNode[prerequisites[i][1]] = {prerequisites[i][0]};
        }  
    }
    for (int i = 0; i < numCourses;i++){
        if(inToNum.find(i) == inToNum.end()){
            canOutNode.push_back(i);
        }
    }
    while(!canOutNode.empty()){
        int curNode = canOutNode.back();
        canOutNode.pop_back();
        outNode.push_back(curNode);
        for (int i = 0; i < outToNode[curNode].size();i++){
            inToNum[outToNode[curNode][i]]--;
            if(inToNum[outToNode[curNode][i]] == 0){
                canOutNode.push_back(outToNode[curNode][i]);
            }
        }
    }
    if(outNode.size() == numCourses){
        return true;
    }
    return false;
}

int main()
{
    vector<vector<int>> ss = {{0, 1}};
    canFinish(2, ss);
}