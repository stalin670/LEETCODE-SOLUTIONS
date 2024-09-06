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
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int lDepth = maxDepth(root -> left);
        int rDepth = maxDepth(root -> right);

        return max(lDepth, rDepth) + 1;
    }
    void preOrder(TreeNode* root, int& sum, int h, int currH) {
        if(root == NULL)
            return;
        if(root -> left == NULL and root -> right == NULL and currH == h and root != NULL) {
            sum += root -> val;
            return;
        }
        preOrder(root -> left, sum, h, currH + 1);
        preOrder(root -> right, sum, h, currH + 1);
    }
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        int h = maxDepth(root);
        preOrder(root, sum, h, 1);
        return sum;
    }
};