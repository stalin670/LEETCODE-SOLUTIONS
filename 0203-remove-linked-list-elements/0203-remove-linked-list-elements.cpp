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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
            return head;
        while(head and head -> val == val) 
            head = head -> next;
        if(head == NULL || head -> next == NULL)
            return head;
        ListNode* ptr = head;
        while(ptr -> next != NULL) {
            if(ptr -> next -> val == val) {
                ptr -> next = ptr -> next -> next;
            }
            else {
                ptr = ptr -> next;
            }
        }
        return head;
    }
};