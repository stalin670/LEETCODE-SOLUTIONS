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
    pair<int,int> solve(TreeNode* root, int & ans){
        if(root == NULL) return {0,0};

        auto f = solve(root->left , ans);
        auto s = solve(root->right , ans);

        int total = f.first + s.first + root->val;
        int noOfElements = f.second + s.second + 1;

        if(total / noOfElements == root->val) ans++;

        return {total , noOfElements};
    }

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        auto it = solve(root , ans);
        return ans;
    }
};