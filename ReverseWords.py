class Solution:
    def reverseWords(self, s: str) -> str:
        i = 0
        temp = []
        while i < len(s):
            if s[i] == ' ':
                i+=1
            else:
                w = ''
                while i < len(s) and s[i] != ' ':
                    w = w+s[i]
                    i+=1
                temp.append(w)
        t = temp[::-1]
        ret = ''
        for i in range(len(t)):
            ret = ret+t[i]
            if i != len(t)-1:
                ret = ret+' '
        return ret
