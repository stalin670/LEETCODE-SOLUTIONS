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
    int helper(TreeNode* root, int &ans) {
        if(!root)
            return 0;
        int left_sum = helper(root -> left, ans);
        int right_sum = helper(root -> right, ans);
        
        int max_sum1 = max(max(left_sum, right_sum) + root -> val, root -> val);
        int max_sum2 = max(max_sum1, left_sum + right_sum + root -> val);
        ans = max(ans, max_sum2);
        
        return max_sum1;
    }
    
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        helper(root, ans);
        return ans;
    }
};