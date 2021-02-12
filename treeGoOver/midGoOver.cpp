#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct treeNode{
    treeNode *left;
    treeNode *right;
    int value;
};

vector<int> midGoOver(treeNode*root){
    stack<treeNode *> nodes;
    vector<int> res;
    while(!nodes.empty()||root!=nullptr){
        while(root!=nullptr){
            nodes.push(root);
            root = root->left;
        }
        root = nodes.top();
        nodes.pop();
        res.push_back(root->value);
        root = root->right;
    }
    return res;
}