'''

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

'''


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:

        if(digits == ""):
            return []
        else:
            d = {2:['a','b','c'],3:['d','e','f'],4:['g','h','i'],5:['j','k','l'],6:['m','n','o'],
            7:['p','q','r','s'],8:['t','u','v'],9:['w','x','y','z']}
            
            l = []
            for i in digits:
                if(int(i) in d.keys()):
                    l.append(d[int(i)])
            
            combinations = ['']
            for letterpos in l:
                new_combinations = []
                for combination in combinations:
                    for letter in letterpos:
                        new_combinations.append(combination + letter)
                combinations = new_combinations
            return combinations

                

            

