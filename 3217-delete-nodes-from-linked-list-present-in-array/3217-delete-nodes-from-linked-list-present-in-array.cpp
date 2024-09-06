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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<ll> st;
        for(auto it : nums)
            st.insert(it);
        
        while(st.find(head -> val) != st.end())
            head = head -> next;
        
        ListNode* t = head;
        while(t -> next != nullptr) {
            if(st.find(t -> next -> val) != st.end()) {
                t -> next = t -> next -> next;
            }
            else {
                t = t -> next;
            }
        }
        return head;
    }
};