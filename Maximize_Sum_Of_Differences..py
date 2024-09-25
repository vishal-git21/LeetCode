def maximize_sum_of_differences(arr, m):
    n = len(arr)
    
    # Sort the array
    arr.sort()
    

    dp = [[float('-inf')] * (m + 1) for _ in range(n)]
    
    for i in range(n):
        dp[i][1] = 0
    

    for i in range(1, n):
        for k in range(2, m + 1):
            for j in range(i):
                dp[i][k] = max(dp[i][k], dp[j][k-1] + (arr[i] - arr[j]))

    result = float('-inf')
    for i in range(m - 1, n):
        result = max(result, dp[i][m])
    
    return result


