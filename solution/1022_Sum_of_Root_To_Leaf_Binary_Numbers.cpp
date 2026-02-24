// LC: 1022 Sum of Root To Leaf Binary Numbers
// Title: Sum of Root To Leaf Binary Numbers
// Difficulty: Easy
// Date: 24 Feb 2026

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
    int rec(int val, TreeNode* root){


        int x = val << 1;
        x |= root->val;

        int left = 0, right = 0;

        if(root->left != nullptr)
            left = rec(x, root->left);
        if(root->right != nullptr)
             right = rec(x, root->right);

        int y = left + right;

        if(y == 0) y = x;

        return y;

    }
    int sumRootToLeaf(TreeNode* root) {

       return  rec(0, root);

        
    }
};
