#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *rle(char *s) {
    int iter = 0;
    int buf_size = 200;
    char *ret = malloc(buf_size);  
    int loc = 0;

    while (s[iter] != '\0') {
        if (loc + 2 >= buf_size) {
            buf_size *= 2;
            ret = realloc(ret, buf_size);
        }

        ret[loc + 1] = s[iter];
        int count = 0;

        while (s[iter] != '\0' && s[iter] == ret[loc + 1]) {
            count++;
            iter++;
        }

        ret[loc] = count + '0';
        loc += 2;
    }

    ret[loc] = '\0';
    return ret;
}

char *countAndSay(int n) {
    if (n == 1) {
        char *a = malloc(2);
        strcpy(a, "1");
        return a;
    } else {
        char *prev = countAndSay(n - 1);
        char *result = rle(prev);
        free(prev);
        return result;
    }
}
