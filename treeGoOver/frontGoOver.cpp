#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct treeNode{
    treeNode *left;
    treeNode *right;
    int value;
};

vector<int> frontGoOver(treeNode* root){
    stack<treeNode *> nodes;
    vector<int> res;
    while(root != nullptr || !nodes.empty()){
        while(root!=nullptr){
            res.push_back(root->value);
            nodes.push(root);
            root = root->left;
        }
        root = nodes.top();
        nodes.pop();
        root = root->right;
    }
    return res;
}