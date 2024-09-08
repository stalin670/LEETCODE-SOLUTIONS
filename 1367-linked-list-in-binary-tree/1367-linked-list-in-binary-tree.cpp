/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool check(ListNode* node, TreeNode* root, ListNode* head) {
        if(node == NULL)
            return true;
        
        if(root == NULL)
            return false;
        
        if(root -> val == node -> val) {
            node = node -> next;
        }
        else if(head -> val == root -> val) {
            head = head -> next;
        }
        else {
            node = head;
        }
        return check(node, root -> left, head) | check(node, root -> right, head);
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        return check(head, root, head);
    }
};