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
    bool checker(TreeNode* p, TreeNode* q) {
        if(p == NULL and q == NULL)
            return true;
        if((p == NULL and q != NULL) || (p != NULL and q == NULL))
            return false;
        if(p -> val != q -> val)
            return false;
        
        bool left_subtree = checker(p -> left, q -> left);
        bool right_subtree = checker(p -> right, q -> right);
        return left_subtree and right_subtree;
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return checker(p, q);
    }
};