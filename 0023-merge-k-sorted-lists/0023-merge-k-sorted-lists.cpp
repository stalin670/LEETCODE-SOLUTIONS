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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(-1);
        ListNode* ptr = head;
        vector<ll> arr;
        for(ll i = 0; i < lists.size(); i++) {
            ListNode* temp = lists[i];
            while(temp != NULL) {
                arr.push_back(temp -> val);
                temp = temp -> next;
            }
        }
        sort(arr.begin(), arr.end());
        ll i = 0;
        while(i < arr.size()) {
            ptr -> next = new ListNode(arr[i]);
            ptr = ptr -> next;
            i++;
        }
        return head -> next;
    }
};