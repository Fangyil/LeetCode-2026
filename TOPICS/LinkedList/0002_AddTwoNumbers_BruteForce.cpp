//Runtime: 35ms, Beats: 6.31%
  
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int i;
    struct ListNode* result = malloc(sizeof(struct ListNode));
    struct ListNode* answer = result;

    result -> val = 0;
    result -> next = NULL;

    while( l1|| l2){

        if ( l1&& l2){
            printf("1. %d %d",l1->val, l2->val);
            if ( result -> val + l1 -> val + l2 -> val > 9){
                i = result -> val + l1 -> val + l2 -> val;
                result -> val = i % 10;
                result -> next = malloc(sizeof(struct ListNode));
                result -> next -> val = i / 10;
                result -> next -> next = NULL;
            }
            else
                result -> val += l1 -> val + l2 -> val;
        }
        else if (l1){
            printf("2. %d",l1->val);
            if ( result -> val + l1 -> val > 9){
                i = result -> val + l1 -> val;
                result -> val = i % 10;
                result -> next = malloc(sizeof(struct ListNode));
                result -> next -> val =  i / 10;
                result -> next -> next = NULL;
            }
            else
                result -> val += l1 -> val;
        }
        else if (l2){
            printf("3. %d",l2->val);
            if ( result -> val + l2 -> val > 9){
                i = result -> val + l2 -> val;
                result -> val = i % 10;
                result -> next = malloc(sizeof(struct ListNode));
                result -> next -> val =  i / 10;
                result -> next -> next = NULL;
            }
            else
                result -> val += l2 -> val;
        }

        printf(" %d\n", result->val);

        if(l1)
            l1 = l1 -> next;
        if(l2)
            l2 = l2 -> next;
        
        if(!result -> next && ( l1|| l2)){
            result -> next = malloc(sizeof(struct ListNode));
            result -> next -> val = 0;
            result -> next -> next = NULL;
        }
        result = result -> next;
    }

    result = NULL;

    return answer;
}
