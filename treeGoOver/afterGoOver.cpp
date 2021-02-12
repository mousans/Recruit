#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct treeNode{
    treeNode *left;
    treeNode *right;
    int value;
};

vector<int> afterGoOver(treeNode* root){
    vector<int> res;
    stack<treeNode *> nodes;
    treeNode *lastNode = nullptr;
    while(root!=nullptr){
        nodes.push(root);
        root = root->left;
    }
    while(!nodes.empty()){
        treeNode *curNode = nodes.top();
        if(curNode->right==nullptr|| curNode->right==lastNode){
            res.push_back(curNode->value);
            lastNode = curNode;
            nodes.pop();
        }else{
            curNode = curNode->right;
            while(curNode!=nullptr){
                nodes.push(curNode);
                curNode = curNode->left;
            }
        }
    }
    return res;
}