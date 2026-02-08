// LC: 110 Balanced Binary Tree
// Title: Balanced Binary Tree
// Difficulty: Easy
// Date: 08 Feb 2026

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
public:
    bool ans = true;
    int rec(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int left = rec(root->left);
        int right = rec(root->right);

        ans &= (abs(left - right) < 2);

        return 1 + max(left,right);

    }
    bool isBalanced(TreeNode* root) {
        rec(root);
        return ans;
    }
};
