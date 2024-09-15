def longestCommonSubstring(text1, text2):
    # Get the lengths of both strings
    m, n = len(text1), len(text2)
    
    # Create a 2D DP array to store the lengths of common substrings
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    longest = 0  # To store the length of the longest common substring
    
    # Fill the DP array
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if text1[i - 1] == text2[j - 1]:
                # If the characters match, extend the substring length by 1
                dp[i][j] = dp[i - 1][j - 1] + 1
                longest = max(longest, dp[i][j])  # Update longest if needed
            else:
                # If they don't match, reset the length of the common substring to 0
                dp[i][j] = 0
    
    # The 'longest' variable holds the length of the longest common substring
    return longest

# Example usage
text1 = "abcde"
text2 = "abfce"
print(longestCommonSubstring(text1, text2))  # Output: 2 (The longest common substring is "ab")
