#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} 
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
/**
 * 前序遍历的vector内的节点为： 根节点|左子树节点|右子树节点
 * 中序遍历的vector内的节点为： 左子树节点|根节点|右节点
 * 所以每次只需要确定两个数组内的根节点位置就能划分出左右子树，所以不用重新构造数组，直接用下标表示，递归结束条件为r>l表明没有节点了
 * */
class Solution {
public:
    unordered_map<int, int> mps;
    TreeNode* build(vector<int>& preorder,int lPre,int rPre,vector<int>&inorder,int lIn,int rIn){
        if(lPre>rPre){ 
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[lPre]);
        int inorderIndex = mps[preorder[lPre]];

        root->left = build(preorder, lPre + 1, lPre + inorderIndex - lIn, inorder, lIn, inorderIndex - 1);
        root->right = build(preorder, lPre + inorderIndex - lIn + 1, rPre, inorder, inorderIndex + 1, rIn);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size();i++){
            mps[inorder[i]] = i;
        }
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};

int main()
{

}