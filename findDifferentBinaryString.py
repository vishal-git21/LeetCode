class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        ret = []
        def backtrack(current,n):
            if len(current) == n:
                if current not in nums:
                    ret.append(current)
                return
            backtrack(current+'0',n)
            backtrack(current+'1',n)
        backtrack('',len(nums[0]))
        return ret[0]
        


        