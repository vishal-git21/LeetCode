import heapq
from typing import List

class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        # Initialize the graph
        graph = {}
        for source, dest, cost in flights:
            if source not in graph:
                graph[source] = []
            graph[source].append((dest, cost))
        
        # Min-heap to store (cost, city, remaining stops)
        heap = [(0, src, k + 1)]
        # Dictionary to keep track of minimum cost to reach a city with a given number of stops
        min_cost = {}
        
        while heap:
            cost, city, stops = heapq.heappop(heap)
            # If the destination city is reached, return the cost
            if city == dst:
                return cost
            # If there are remaining stops
            if stops > 0:
                # Check all neighbors
                if city in graph:
                    for neighbour, price in graph[city]:
                        new_cost = cost + price
                        # Update the minimum cost if we find a cheaper way to get to the neighbor
                        if (neighbour, stops - 1) not in min_cost or new_cost < min_cost[(neighbour, stops - 1)]:
                            min_cost[(neighbour, stops - 1)] = new_cost
                            heapq.heappush(heap, (new_cost, neighbour, stops - 1))
        
        return -1
