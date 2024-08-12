class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []
        candidates.sort()

        def backtrack(remaining,start,path):
            if remaining == 0:
                result.append(path)
                return
            elif remaining < 0:
                return
            else:
                for i in range(start,len(candidates)):
                    if candidates[i] > remaining:
                        break
                    backtrack(remaining-candidates[i],i,path+[candidates[i]])
        backtrack(target,0,[])
        return result
        
        

        