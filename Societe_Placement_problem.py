import heapq

def find_cheapest_price(N, routes, src, dest, k)
    adj = {i [] for i in range(N)}
    for from_hub, to_hub, route_price in routes
        adj[from_hub].append((to_hub, route_price))
   
    pq = [(0, src, 0)]
   
    best = {}
   
    while pq
        cost, current_hub, stops = heapq.heappop(pq)
       
        if current_hub == dest
            return cost
       
        if stops  k
            continue

        if (current_hub, stops) in best and best[(current_hub, stops)] = cost
            continue

        best[(current_hub, stops)] = cost
       
        for neighbor, price in adj[current_hub]
            new_cost = cost + price
            heapq.heappush(pq, (new_cost, neighbor, stops + 1))
  
    return -1

