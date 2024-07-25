'''Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.'''

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        flag = True
        boxes = [set() for _ in range(9)]
        for i in range(9):
            for j in range(9):
                item = board[i][j]
                if item == ".":
                    continue
                if(board[i].count(item)) > 1:
                    return False
                l = []
                for k in range(0,9):
                    l.append(board[k][j])
                if(l.count(item)>1):
                    return False
                box_index = (i//3)*3+(j//3)
                if item in boxes[box_index]:
                    return False
                boxes[box_index].add(item)
                
        return True

        