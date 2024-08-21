class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        matrix = []
        for i in range(n):
            matrix.append([])
        for j in range(n):
            for k in range(n):
                matrix[j].append(0)
        i = 1
        x,y = 0,0
        d = "right"
        while i <= n * n:
            matrix[x][y] = i  
            i += 1
            if d == "right":
                if y + 1 < n and matrix[x][y + 1] == 0:
                    y += 1
                else:
                    d = "down"
                    x += 1
            elif d == "down":
                if x + 1 < n and matrix[x + 1][y] == 0:
                    x += 1
                else:
                    d = "left"
                    y -= 1
            elif d == "left":
                if y - 1 >= 0 and matrix[x][y - 1] == 0:
                    y -= 1
                else:
                    d = "up"
                    x -= 1
            elif d == "up":
                if x - 1 >= 0 and matrix[x - 1][y] == 0:
                    x -= 1
                else:
                    d = "right"
                    y += 1
        
        return matrix
