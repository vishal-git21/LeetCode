class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        l = []
        for i in range(len(nums)-1):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            start = i+1
            end = len(nums)-1
            while(start < end):
                if nums[start]+nums[i]+nums[end] > 0:
                    end -=1
                elif nums[start]+nums[i]+nums[end] < 0:
                    start += 1
                else:
                    l.append([nums[i],nums[start],nums[end]])
                    start+=1
                    end-=1
                    while start < end and nums[start] == nums[start-1]:
                        start += 1 
                    while start < end and nums[end] == nums[end+1]:
                        end-=1
        return l


        