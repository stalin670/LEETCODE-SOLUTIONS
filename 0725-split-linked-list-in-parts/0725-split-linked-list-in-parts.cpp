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
class Solution {
public:
    #define ll long long 
    
    ll LinkedListLen(ListNode* node) {
        ll len = 0;
        while(node != NULL) {
            len++;
            node = node -> next;
        }
        return len;
    }
    
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        ll len = LinkedListLen(head);
        ListNode* ptr = head;
        if(k >= len) {
            while(ptr != NULL) {
                // cout << ptr -> val << " ";
                ListNode* node = new ListNode(ptr -> val);
                ans.push_back(node);
                ptr = ptr -> next;
            }
            ListNode* node = NULL;
            while(ans.size() != k) {
                ans.push_back(node);
            }
        }
        else {
            ll least = len / k;
            ll rem = len % k;
            for(ll i = 1; i <= rem; i++) {
                ll need = least + 1;
                ll j = 0;
                ListNode* temp = new ListNode(-1);
                ListNode* p = temp;
                while(j < need) {
                    temp -> next = new ListNode(ptr -> val);
                    temp = temp -> next;
                    ptr = ptr -> next;
                    j++;
                }
                ans.push_back(p -> next);
            }
            for(ll i = 1; i <= (k - rem); i++) {
                ll need = least;
                ll j = 0;
                ListNode* temp = new ListNode(-1);
                ListNode* p = temp;
                while(j < need) {
                    temp -> next = new ListNode(ptr -> val);
                    temp = temp -> next;
                    ptr = ptr -> next;
                    j++;
                }
                ans.push_back(p -> next);
            }
        }
        
        return ans;
    }
};