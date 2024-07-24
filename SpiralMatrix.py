# Given an m x n matrix, return all elements of the matrix in spiral order.


from typing import List

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return []
        
        l = []
        m = len(matrix)
        n = len(matrix[0])
        i, j = 0, 0
        arrow = "right"
        
        while len(l) < m * n:
            l.append(matrix[i][j])
            matrix[i][j] = None  
            
            if arrow == "right":
                if j + 1 < n and matrix[i][j + 1] is not None:
                    j += 1
                else:
                    arrow = "down"
                    i += 1
            elif arrow == "down":
                if i + 1 < m and matrix[i + 1][j] is not None:
                    i += 1
                else:
                    arrow = "left"
                    j -= 1
            elif arrow == "left":
                if j - 1 >= 0 and matrix[i][j - 1] is not None:
                    j -= 1
                else:
                    arrow = "up"
                    i -= 1
            elif arrow == "up":
                if i - 1 >= 0 and matrix[i - 1][j] is not None:
                    i -= 1
                else:
                    arrow = "right"
                    j += 1
        
        return l


