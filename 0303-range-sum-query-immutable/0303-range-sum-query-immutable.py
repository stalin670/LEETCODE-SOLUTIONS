class NumArray:
    def __init__(self, nums: List[int]):
        self.nums = nums
        self.pref = [0] * len(nums)
        self.pref[0] = nums[0]
        for i in range (1, len(nums)):
            self.pref[i] = self.pref[i - 1] + nums[i]

    def sumRange(self, left: int, right: int) -> int:
        if left == 0:
            return self.pref[right]
        else:
            return self.pref[right] - self.pref[left - 1]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)