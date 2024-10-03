class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        total_sum = sum(nums)
        remainder = total_sum % p
        if remainder == 0:
            return 0  # The total sum is already divisible by p

        # Use a hash map to store prefix sums modulo p
        prefix_map = {0: -1}  # Initialize with 0 at index -1
        prefix_sum = 0
        min_length = len(nums)

        for i, num in enumerate(nums):
            prefix_sum += num
            current_remainder = prefix_sum % p
            target = (current_remainder - remainder + p) % p

            # Check if the target remainder exists in the hash map
            if target in prefix_map:
                min_length = min(min_length, i - prefix_map[target])

            # Update the hash map with the current remainder
            prefix_map[current_remainder] = i

        return min_length if min_length < len(nums) else -1