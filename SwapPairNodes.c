/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp = head;
    if(temp == NULL || temp->next == NULL){
        return temp;
    }
    else{
        struct ListNode *first = (struct ListNode *)malloc(sizeof(struct ListNode));
        first->next = head->next;
        struct ListNode *prev = (struct ListNode *)malloc(sizeof(struct ListNode));
        prev->next = head;
        while(temp != NULL && temp->next != NULL){
            prev->next = temp->next;
            temp->next = temp->next->next;
            prev->next->next = temp;
            prev = temp;
            temp = temp->next;
        }
        return first->next;
    }
}