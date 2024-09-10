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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == NULL || head -> next == NULL)
            head;
        ListNode* ptr = head;
        while(ptr -> next != NULL) {
            ll cur_val = ptr -> val;
            ll next_val = ptr -> next -> val;
            ll gc_d = __gcd(cur_val, next_val);
            ListNode* node = new ListNode(gc_d);
            node -> next = ptr -> next;
            ptr -> next = node;
            
            ptr = ptr -> next -> next;
        }
        return head;
    }
};