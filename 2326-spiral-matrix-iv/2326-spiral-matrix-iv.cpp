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
    // #define ll long long
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
        vector<vector<int>> ans(n, vector<int>(m, - 1));
        int top = 0, bottom = n - 1, left = 0, right = m - 1;
 
        while (head != NULL) {
            if (left > right)
                break;
            // print top row
            for (int i = left; i <= right and head != NULL; i++) {
                ans[top][i] = head -> val;
                head = head -> next;
            }
            top++;
            if (top > bottom)
                break;
            // print right column
            for (int i = top; i <= bottom and head != NULL; i++) {
                ans[i][right] = head -> val;
                head = head -> next;
            }
            right--;
            if (left > right)
                break;
            // print bottom row
            for (int i = right; i >= left and head != NULL; i--) {
                ans[bottom][i] = head -> val;
                head = head -> next;
            }
            bottom--;
            if (top > bottom)
                break;
            // print left column
            for (int i = bottom; i >= top and head != NULL; i--) {
                ans[i][left] = head -> val;
                head = head -> next;
            }
            left++;
        }
        return ans;
    }
};