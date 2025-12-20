class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        n = len(nums)
        self.pref = [0] * n
        self.suff = [0] * n

        self.pref[0] = nums[0]
        for i in range(1, n):
            self.pref[i] = self.pref[i - 1] + nums[i]

        self.suff[n - 1] = nums[n - 1]
        for i in range(n - 2, 0, -1):
            self.suff[i] = self.suff[i + 1] + nums[i]

        if n == 1:
            return 0
        
        if self.suff[1] == 0:
            return 0
        
        for i in range(1, n - 1):
            if self.pref[i - 1] == self.suff[i + 1]:
                return i
        
        if self.pref[n - 2] == 0:
            return n - 1

        return -1