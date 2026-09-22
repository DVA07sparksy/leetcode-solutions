// 0 ms | 13.5 MB
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {


    struct ListNode *head = NULL;
    struct ListNode *tail = NULL;
    int count = 0;
    while(l1 != NULL || l2 != NULL){
        int sum = 0;
        if(l1 != NULL){
            sum = sum + (*l1).val;
            l1 = (*l1).next;
        }
    
        if(l2 != NULL){
            sum = sum + (*l2).val;
            l2 = (*l2).next;
        }
        sum = sum + count;


        if(sum>=10){
            sum = sum - 10;
            count = 1;//count should either be 0 or 1
        }else {
            count = 0;
        }
        struct ListNode *result = malloc(sizeof(struct ListNode));

        (*result).val = sum;
        (*result).next = NULL;

        if (head == NULL) {
            head = result;
            tail = result;
        } else {
            (*tail).next = result;
            tail = result;
        }
    }
    // since for case 3 carry has to be added extra
    if(count == 1){
        struct ListNode *result = malloc(sizeof(struct ListNode));

        (*result).val = count;
        (*result).next = NULL;

        (*tail).next = result;
        tail = result;
    }

    return head;
}
