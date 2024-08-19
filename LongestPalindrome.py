class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s) <= 1:
            return s
        
        maxlength = 1
        st = s[0]
        
        for i in range(1, len(s) - 1):
            l = i - 1
            r = i + 1
            while l >= 0 and r < len(s) and s[l] == s[r]:
                l -= 1
                r += 1
            curlength = r - l - 1
            if curlength > maxlength:
                maxlength = curlength
                st = s[l + 1:r]
        
        for i in range(len(s) - 1):
            if s[i] == s[i + 1]:
                l = i - 1
                r = i + 2
                while l >= 0 and r < len(s) and s[l] == s[r]:
                    l -= 1
                    r += 1
                curlength = r - l - 1
                if curlength > maxlength:
                    maxlength = curlength 
                    st = s[l + 1:r]

        return st

