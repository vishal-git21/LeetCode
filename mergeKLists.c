#include <limits.h>

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode *pointers = (struct ListNode **)malloc(listsSize * sizeof(struct ListNode));
    for (int i = 0; i < listsSize; i++) {
        pointers[i] = lists[i];
    }

    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = NULL;
    struct ListNode *prev = dummy;

    int flag = 1;
    while (flag) {
        int maxindex = -1;
        int maxval = INT_MAX;

        for (int i = 0; i < listsSize; i++) {
            if (pointers[i] != NULL && pointers[i]->val < maxval) {
                maxindex = i;
                maxval = pointers[i]->val;
            }
        }

        if (maxindex == -1) {
            flag = 0;
        } else {
            struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
            temp->val = maxval;
            temp->next = NULL;
            prev->next = temp;
            prev = temp;

            pointers[maxindex] = pointers[maxindex]->next;
        }
    }

    struct ListNode *result = dummy->next;
    free(dummy);
    free(pointers);

    return result;
}