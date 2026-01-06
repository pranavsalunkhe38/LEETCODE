// LC: 1161 Maximum Level Sum of a Binary Tree
// Title: Maximum Level Sum of a Binary Tree
// Difficulty: Easy
// Date: 06 Jan 2026

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
    int maxLevelSum(TreeNode *root)
    {

        int ans = INT_MIN, ansl = 0;

        queue<TreeNode *> q;
        q.push(root);

        for (int i = 1; !q.empty(); i++)
        {

            int sz = q.size();
            int sum = 0;

            for (int i = 0; i < sz; i++)
            {

                auto top = q.front();
                q.pop();
                sum += top->val;

                if (top->left != nullptr)
                {
                    q.push(top->left);
                }

                if (top->right != nullptr)
                {
                    q.push(top->right);
                }
            }

            if (sum > ans)
            {
                ansl = i;
                ans = sum;
            }
        }

        return ansl;
    }
};
