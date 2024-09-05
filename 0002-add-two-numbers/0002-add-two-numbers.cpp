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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        vector<ll> a, b;
        while(t1 != nullptr) {
            a.push_back(t1 -> val);
            t1 = t1 -> next;
        }
        while(t2 != nullptr) {
            b.push_back(t2 -> val);
            t2 = t2 -> next;
        }
        // reverse(a.begin(), a.end());
        // reverse(b.begin(), b.end());
        vector<ll> ans;
        ll n = a.size(), m = b.size();
        ll i = 0, j = 0;
        ll carry = 0;
        while(i < n and j < m) {
            ll curr_node_sum = a[i] + b[j] + carry;
            if(curr_node_sum <= 9) {
                ans.push_back(curr_node_sum);
                carry = 0;
            }
            else {
                ans.push_back(curr_node_sum % 10);
                carry = curr_node_sum / 10;
            }
            i++;
            j++;
        }
        
        while(i < n) {
            ll curr_node_sum = a[i] + carry;
            if(curr_node_sum <= 9) {
                ans.push_back(curr_node_sum);
                carry = 0;
            }
            else {
                ans.push_back(curr_node_sum % 10);
                carry = curr_node_sum / 10;
            }
            i++;
        }
        
        while(j < m) {
            ll curr_node_sum = b[j] + carry;
            if(curr_node_sum <= 9) {
                ans.push_back(curr_node_sum);
                carry = 0;
            }
            else {
                ans.push_back(curr_node_sum % 10);
                carry = curr_node_sum / 10;
            }
            j++;
        }
        
        if(carry) 
            ans.push_back(carry);
        
        // reverse(ans.begin(), ans.end());
        
        ll final_size = ans.size();
        ListNode* ans_list = new ListNode(ans[0]);
        ListNode* temp = ans_list;
        for(i = 1; i < final_size; i++) {
            temp -> next = new ListNode(ans[i]);
            temp = temp -> next;
        }
        return ans_list;
    }
};