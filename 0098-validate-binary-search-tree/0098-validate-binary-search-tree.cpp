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
    #define ll long long
    bool check(TreeNode* root, ll mini, ll maxi) {
        if(root == NULL)
            return true;
        if(root -> val <= mini || root -> val >= maxi) 
            return false;
        
        bool left_check = check(root -> left, mini, root -> val);
        bool right_check = check(root -> right, root -> val, maxi);
        
        return left_check and right_check;
    }
    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};