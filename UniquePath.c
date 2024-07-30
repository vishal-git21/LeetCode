/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(head == NULL || head->next == NULL){
        return head;
    }
    else{
        int length = 0;
        struct ListNode *iter = (struct ListNode *)malloc(sizeof(struct ListNode));
        iter = head;
        while(iter != NULL){
            length++;
            iter = iter->next;
        }
        int i  = 0;
        int remainder = k - (k/length)*length;
        printf("%d",remainder);
        while(i<remainder){
            struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
            temp = head;
            struct ListNode *prev = (struct ListNode *)malloc(sizeof(struct ListNode));
            prev = NULL;
            while(temp->next != NULL){
                prev = temp;
                temp = temp->next;
            }
            prev->next = NULL;
            temp->next = head;
            head = temp;
            i++;
        }
        return head;
    }
}