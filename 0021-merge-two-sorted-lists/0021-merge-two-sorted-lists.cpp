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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ptr = new ListNode(-1);
        ListNode* head = ptr;
        ptr = head;
        while(list1 != NULL and list2 != NULL) {
            ll fVal = list1 -> val;
            ll sVal = list2 -> val;
            if(fVal < sVal) {
                ListNode* node = new ListNode(fVal);
                ptr -> next = node;
                list1 = list1 -> next;
            }
            else {
                ListNode* node = new ListNode(sVal);
                ptr -> next = node;
                list2 = list2 -> next;
            }
            ptr = ptr -> next;
        }
        while(list1 != NULL) {
            ll fVal = list1 -> val;
            ListNode* node = new ListNode(fVal);
            ptr -> next = node;
            list1 = list1 -> next;
            ptr = ptr -> next;
        }
        while(list2 != NULL) {
            ll sVal = list2 -> val;
            ListNode* node = new ListNode(sVal);
            ptr -> next = node;
            list2 = list2 -> next;
            ptr = ptr -> next;
        }
        return head -> next;
    }
};