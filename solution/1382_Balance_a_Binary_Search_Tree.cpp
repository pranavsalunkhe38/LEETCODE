// LC: 1382 Balance a Binary Search Tree
// Title: Balance a Binary Search Tree
// Difficulty: Medium
// Date: 09 Feb 2026

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<int> v;
public:
    void inOrder(TreeNode* root){
        if(root == nullptr) return;
        inOrder(root->left);
        v.push_back(root->val);
        inOrder(root->right);
    }

    TreeNode* build(int i, int j){
        if(i > j) return nullptr;
        int mid = i + (j - i)/2;

        TreeNode* left = build(i,mid-1);
        TreeNode* right = build(mid+1,j);

        return new TreeNode(v[mid], left,right);

    }
    TreeNode* balanceBST(TreeNode* root) {

        inOrder(root);
        // for(auto i: v){
        //     cout<<i<<endl;
        // }

        return build(0, v.size()-1);
        
    }
};
