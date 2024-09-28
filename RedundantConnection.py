class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        def find(parent,x):
            if parent[x] != x:
                parent[x] = find(parent,parent[x])
            return parent[x]


        def union(parent,rank,u,v):
            rootX = find(parent,u)
            rootY = find(parent,v)

            if rootX != rootY:
                if rank[rootX] > rank[rootY]:
                    parent[rootY] = rootX
                elif rank[rootX] < rank[rootY]:
                    parent[rootX] = rootY
                else:
                    parent[rootY] = rootX
                    rank[rootX]+=1
                return True
            return False

        n = len(edges)
        parent = [i for i in range(n+1)]
        rank = [1]*(n+1)
        for u,v in edges:
            if not union(parent,rank,u,v):
                return [u,v]
        
        