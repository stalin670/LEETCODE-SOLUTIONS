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
    ll len(ListNode * list) {
        ll x = 0;
        while(list != NULL) {
            x++;
            list = list -> next;
        }
        return x;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ll size = len(head);
        if(size == n)
            return head -> next;
        ll need = size - n;
        
        ListNode* ptr = head;
        ll i = 1;
        // cout << need << endl;
        while(i != need) {
            ptr = ptr -> next;
            i++;
        }
        // cout << ptr -> val << endl;
        ptr -> next = ptr -> next -> next;
        return head;
    }
};