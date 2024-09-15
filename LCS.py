def longestCommonSubsequence(text1, text2):
    # Get the lengths of both strings
    m, n = len(text1), len(text2)
    
    # Create a 2D DP array to store the lengths of LCS for substrings
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    
    # Fill the DP array
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if text1[i - 1] == text2[j - 1]:
                # If the characters match, take the diagonal value + 1
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                # If they don't match, take the max of the value from the left or above
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
    
    # The bottom-right corner will have the length of LCS
    return dp[m][n]

# Example usage
text1 = "abcde"
text2 = "ace"
print(longestCommonSubsequence(text1, text2))  # Output: 3
