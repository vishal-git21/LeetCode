struct ListNode* partition(struct ListNode* head, int x) {
    if (!head || head->next == NULL) {
        return head;
    }

    struct ListNode *part1 = NULL, *part2 = NULL;
    struct ListNode *part1_tail = NULL, *part2_tail = NULL;
    struct ListNode *iter = head;

    while (iter != NULL) {
        if (iter->val < x) {
            if (part1 == NULL) {
                part1 = iter;
                part1_tail = part1;
            } else {
                part1_tail->next = iter;
                part1_tail = iter;
            }
        } else {
            if (part2 == NULL) {
                part2 = iter;
                part2_tail = part2;
            } else {
                part2_tail->next = iter;
                part2_tail = iter;
            }
        }
        iter = iter->next;
    }
    if (part1_tail) {
        part1_tail->next = part2;
    }

    if (part2_tail) {
        part2_tail->next = NULL; 
    }

    return part1 ? part1 : part2;
}
