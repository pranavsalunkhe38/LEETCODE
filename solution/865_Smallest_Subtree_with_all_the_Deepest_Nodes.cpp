// LC: 865 Smallest Subtree with all the Deepest Nodes
// Title: Smallest Subtree with all the Deepest Nodes
// Difficulty: Medium
// Date: 09 Jan 2026

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
    TreeNode* ans;
    int mx = -1;

    int rec(TreeNode* root,int level) {
        if(root == nullptr){
            mx = max(mx,level);
            return level;
        }
        int l = rec(root->left, level+1);
        int r = rec(root->right,level+1);

        if(l == r && l == mx){
            ans = root;
        }

        return max(l,r);
        
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
       
        rec(root,0);

        cout<<mx<<endl;

        return ans;
        
        
    }
};
