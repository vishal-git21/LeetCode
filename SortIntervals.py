class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        if not intervals:
            return 0
        intervals.sort(key=lambda x: x[1])
        
        count = 0
        end = float('-inf')
        
        for interval in intervals:
            if interval[0] >= end:
                end = interval[1]
            else:
                count += 1
        
        return count

        