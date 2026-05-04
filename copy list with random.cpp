#include <stdlib.h>

struct Node* copyRandomList(struct Node* head) {
    if (head == NULL) return NULL;

    struct Node *curr, *temp;

    // STEP 1: INTERWEAVE
    // Create a new node for each existing node and insert it 
    // directly after the original node.
    // Original: A -> B -> C
    // Interweaved: A -> A' -> B -> B' -> C -> C'
    curr = head;
    while (curr != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->val = curr->val;
        newNode->next = curr->next;
        newNode->random = NULL;
        
        curr->next = newNode;
        curr = newNode->next;
    }

    // STEP 2: COPY RANDOM POINTERS
    // The copy's random pointer is the original's random->next.
    curr = head;
    while (curr != NULL) {
        if (curr->random != NULL) {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }

    // STEP 3: SEPARATE THE LISTS
    // Restore the original list and extract the copy list.
    curr = head;
    struct Node* newHead = head->next;
    struct Node* copyCurr = newHead;

    while (curr != NULL) {
        curr->next = curr->next->next;
        if (copyCurr->next != NULL) {
            copyCurr->next = copyCurr->next->next;
        }
        
        curr = curr->next;
        copyCurr = copyCurr->next;
    }

    return newHead;
}
