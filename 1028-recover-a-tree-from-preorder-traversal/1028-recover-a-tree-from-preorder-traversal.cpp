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
    TreeNode* recoverFromPreorder(string traversal) {
        ll n = traversal.size();
        ll i = 0;
        TreeNode* root, *temp;
        string s = "";
        map<ll, TreeNode*> mp;
        
        while(i < n and traversal[i] != '-') {
            s += traversal[i];
            i++;
        }
        
        temp = new TreeNode(stoi(s));
        mp[0] = temp;
        root = temp;
        
        while(i < n) {
            ll dash = 0;
            s = "";
            
            while(i < n and traversal[i] == '-') {
                dash++;
                i++;
            }
            
            while(i < n and traversal[i] != '-') {
                s += traversal[i];
                i++;
            }
            
            auto node = new TreeNode(stoi(s));
            if(!mp[dash - 1] -> left) {
                mp[dash - 1] -> left = node;
            }
            else {
                mp[dash - 1] -> right = node;
            }
            
            mp[dash] = node;
        }
        
        return root;
    }
};