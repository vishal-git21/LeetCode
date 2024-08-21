import math
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        l = [i for i in range(1,n+1)]
        s = ''
        k-=1
        for j in range(n,0,-1):
            f = math.factorial(j-1)
            index = k // f 
            s = s + str(l[index])
            l.pop(index)
            k %= f
        return s
