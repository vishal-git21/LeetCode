import heapq
import sys

def dijkstra(graph, start):
    # Initialize distances with infinity
    distances = {node: sys.maxsize for node in graph}
    # Set the distance for the start node to 0
    distances[start] = 0
    
    # Priority queue to keep track of the next node to visit
    priority_queue = [(0, start)]
    
    while priority_queue:
        # Pop the node with the smallest distance
        current_distance, current_node = heapq.heappop(priority_queue)
        
        # If the popped distance is greater than the known distance, skip it
        if current_distance > distances[current_node]:
            continue
        
        # Explore neighbors
        for neighbor, weight in graph[current_node].items():
            distance = current_distance + weight
            
            # If a shorter path is found, update the distance and push to the queue
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(priority_queue, (distance, neighbor))
    
    return distances

# Example graph represented as an adjacency list
graph = {
    'A': {'B': 10, 'C': 5},
    'B': {'A': 10, 'D': 20},
    'C': {'A': 5, 'D': 30, 'B': 15},
    'D': {'B': 20, 'C': 30},
}

# Running Dijkstra's algorithm from node 'A'
distances = dijkstra(graph, 'A')
print("Shortest distances from A:", distances)
