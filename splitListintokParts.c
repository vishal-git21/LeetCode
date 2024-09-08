#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize) {
    struct ListNode* current = head;
    int totalLength = 0;

    while (current) {
        totalLength++;
        current = current->next;
    }

    int partSize = totalLength / k;
    int extraNodes = totalLength % k;

    struct ListNode** result = (struct ListNode**)malloc(k * sizeof(struct ListNode*));
    *returnSize = k;

    current = head;
    for (int i = 0; i < k; i++) {
        result[i] = current;

        int currentPartSize = partSize + (i < extraNodes ? 1 : 0);

        for (int j = 0; j < currentPartSize - 1; j++) {
            if (current) {
                current = current->next;
            }
        }
        if (current) {
            struct ListNode* temp = current->next;
            current->next = NULL;
            current = temp;
        }
    }

    return result;
}
