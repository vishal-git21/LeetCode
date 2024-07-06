class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 0:
            return []
        l = [[1]]
        if numRows == 1:
            return l
        else:
            i = 1
            while i < numRows:
                row = [1] * (i+1)
                for j in range(0,i+1):
                    if j == 0:
                        row[j] = 1
                    elif j == i:
                        row[j] = 1
                    else:
                        row[j] = l[i-1][j-1] + l[i-1][j]
                l.append(row)
                i+=1
        return l
