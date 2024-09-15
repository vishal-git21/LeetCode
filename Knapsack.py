# Function to solve 0/1 Knapsack Problem
def knapsack(weights, values, capacity):
    n = len(values)  # Number of items
    # Create a DP table with dimensions (n+1) x (capacity+1)
    dp = [[0 for _ in range(capacity + 1)] for _ in range(n + 1)]
    
    # Build the table dp[][] in bottom-up manner
    for i in range(1, n + 1):
        for w in range(1, capacity + 1):
            if weights[i - 1] <= w:
                # Include the current item and maximize value
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1])
            else:
                # Exclude the current item
                dp[i][w] = dp[i - 1][w]

    # The bottom-right corner of the table will have the result
    return dp[n][capacity]

# Example usage
values = [60, 100, 120]  # Values of the items
weights = [10, 20, 30]   # Weights of the items
capacity = 50            # Maximum capacity of the knapsack

# Call the function and print the maximum value
max_value = knapsack(weights, values, capacity)
print(f"The maximum value that can be obtained: {max_value}")
