'''

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]

'''


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def backtrack(s = '', l = 0, r = 0):
            if(len(s) == 2 * n):
                res.append(s)
            if l < n:
                backtrack(s+'(',l+1,r)
            if r < l:
                backtrack(s + ')',l,r+1)
        res = []
        backtrack()
        return res


        