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
    void inorder(TreeNode* root, vector<TreeNode*>& tree){
        if(root == NULL){
            return;
        }
        inorder(root->left, tree);
        tree.push_back(root);
        inorder(root->right, tree);
    }
    
    TreeNode* solve(vector<TreeNode*>& tree, int st, int en){
        if(st > en){
            return NULL;
        }
        int mid = (st+en)/2;
        TreeNode* node = tree[mid];
        node->left = solve(tree, st, mid-1);
        node->right = solve(tree, mid+1, en);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> tree;
    	inorder(root, tree);
    	return solve(tree, 0, tree.size()-1);
    }
};