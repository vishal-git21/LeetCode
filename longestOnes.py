class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        left = 0
        maxcount = 0
        zeroes = 0
        
        for right in range(len(nums)):
            if nums[right] == 0:
                zeroes += 1
            

            while zeroes > k:
                if nums[left] == 0:
                    zeroes -= 1
                left += 1
            

            maxcount = max(maxcount, right - left + 1)
        
        return maxcount
