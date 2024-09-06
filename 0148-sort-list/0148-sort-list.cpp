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
    ListNode* sortList(ListNode* head) {
        ListNode* ptr = head;
        vector<ll> arr;
        while(ptr != NULL) {
            arr.push_back(ptr -> val);
            ptr = ptr -> next;
        }
        sort(arr.begin(), arr.end());
        ll i = 0;
        ptr = head;
        while(ptr != NULL) {
            ptr -> val = arr[i];
            ptr = ptr -> next;
            i++;
        }
        return head;
    }
};