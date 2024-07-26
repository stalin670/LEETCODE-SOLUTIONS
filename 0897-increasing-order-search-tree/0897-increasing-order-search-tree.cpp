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
    void inorder(TreeNode* root, vector<int>& inOrder) {
        if(root == NULL)
            return;
        inorder(root->left, inOrder);
        inOrder.push_back(root->val);
        inorder(root->right,inOrder);
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(root == NULL)
            return root;
        vector<int> inOrder;
        inorder(root,inOrder);
        
        TreeNode* node = new TreeNode(inOrder[0]);
        TreeNode* t = node;
        for(int i = 1; i < inOrder.size(); i++) {
            t->right = new TreeNode(inOrder[i]);
            t = t->right;
        }
        return node;
    }
};