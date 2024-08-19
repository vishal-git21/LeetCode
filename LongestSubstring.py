class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        count = 0
        maxcount = 0
        start = 0
        end = 0
        
        while end < len(s):
            if s[end] in s[start:end]:
                start = start + s[start:end].index(s[end]) + 1
            
            count = end - start + 1
            
            if count > maxcount:
                maxcount = count
            
            end += 1
        
        return maxcount

