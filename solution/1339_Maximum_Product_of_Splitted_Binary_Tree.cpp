// LC: 1339 Maximum Product of Splitted Binary Tree
// Title: Maximum Product of Splitted Binary Tree
// Difficulty: Medium
// Date: 07 Jan 2025

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
class Solution
{
public:
    long long mod = 1000000007;

    long long sume(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        return (node->val + sume(node->left) + sume(node->right));
    }

    long long ans = 0;
    long long sum = 0;

    long long rec(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        long long x = root->val;
        x += rec(root->left);
        x += rec(root->right);

        ans = max(ans, ((sum - x) * x));

        return x;
    }

    int maxProduct(TreeNode *root)
    {

        sum = sume(root);
        rec(root);
        return ans % mod;
    }
};
