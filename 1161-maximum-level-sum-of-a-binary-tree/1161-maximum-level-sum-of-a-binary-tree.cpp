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
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);

        int ans = INT_MIN;
        int level = 0, curLevel = 0;
        while(!q.empty()) {
            int sum = 0;
            int n = q.size();
            for(int i = 0; i < n; i++) {
                auto node = q.front();
                sum += node -> val;
                q.pop();

                if(node -> left) 
                    q.push(node -> left);
                if(node -> right)
                    q.push(node -> right);
            }
            curLevel++;
            if(sum > ans) {
                ans = sum;
                level = curLevel;
            }
        }
        return level;
    }
};