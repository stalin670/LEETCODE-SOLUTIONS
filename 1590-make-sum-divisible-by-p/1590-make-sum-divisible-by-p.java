class Solution {
    public int minSubarray(int[] nums, int p) {
        long totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        int remainder = (int) (totalSum % p);
        if (remainder == 0) {
            return 0;  // The total sum is already divisible by p
        }
        
        // Use a hash map to store prefix sums modulo p
        HashMap<Integer, Integer> prefixMap = new HashMap<>();
        prefixMap.put(0, -1);  // Initialize with 0 at index -1
        long prefixSum = 0;
        int minLength = nums.length;
        
        for (int i = 0; i < nums.length; i++) {
            prefixSum += nums[i];
            int currentRemainder = (int) (prefixSum % p);
            int target = (currentRemainder - remainder + p) % p;
            
            // Check if the target remainder exists in the hash map
            if (prefixMap.containsKey(target)) {
                minLength = Math.min(minLength, i - prefixMap.get(target));
            }
            prefixMap.put(currentRemainder, i);
        }
        
        return (minLength == nums.length) ? -1 : minLength;
    }
}