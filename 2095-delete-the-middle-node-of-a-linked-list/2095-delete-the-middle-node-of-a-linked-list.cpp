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
    ll ListLen(ListNode* ptr) {
        ll x = 0;
        while(ptr != NULL) {
            x++;
            ptr = ptr -> next;
        }
        return x;
    }
    ListNode* deleteMiddle(ListNode* head) {
        ll n = ListLen(head);
        
        if(n == 1) {
            head = NULL;
            return head;
        }
        else if(n == 2) {
            head -> next = NULL;
            return head;
        }
        
        ListNode* ptr = head;
        ll toDelete = n / 2;
        ll i = 0;
        while(i < toDelete - 1) {
            ptr = ptr -> next;
            i++;
        }
        ptr -> next = ptr -> next -> next;
        return head;
    }
};