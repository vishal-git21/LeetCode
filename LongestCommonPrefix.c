/*

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.



*/



#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        return strdup("");
    }
    
    int minLen = strlen(strs[0]);
    for (int i = 1; i < strsSize; i++) {
        int len = strlen(strs[i]);
        if (len < minLen) {
            minLen = len;
        }
    }
    
    char* ret = (char*)malloc((minLen + 1) * sizeof(char));
    if (!ret) {
        return NULL;
    }
    
    int j = 0;
    bool flag = true;
    while (flag && j < minLen) {
        char ch = strs[0][j];
        for (int i = 1; i < strsSize; i++) {
            if (strs[i][j] != ch) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ret[j] = ch;
            j++;
        }
    }
    
    ret[j] = '\0';
    return ret;
}
