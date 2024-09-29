class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        incoming = [False]*n
        for u,v in edges:
            incoming[v] = True
        ret = []
        for i in range(len(incoming)):
            if incoming[i] == False:
                ret.append(i)
        return ret


        