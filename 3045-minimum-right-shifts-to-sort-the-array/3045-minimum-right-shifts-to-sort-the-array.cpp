class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());

        for (int rotations = 0; rotations < n; ++rotations) {
            bool isSorted = true;
            for (int i = 0; i < n; ++i) {
                if (nums[i] != sorted[i]) {
                    isSorted = false;
                    break;
                }
            }

            if (isSorted) {
                return rotations;
            }

            int lastElement = nums[n - 1];
            for (int i = n - 1; i > 0; --i) {
                nums[i] = nums[(i - 1 + n) % n];
            }
            nums[0] = lastElement;
        }

        return -1;
    }
};