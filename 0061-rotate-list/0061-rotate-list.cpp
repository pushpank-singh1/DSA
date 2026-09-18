/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0){
            return head;
        }

        // find length and tail
        int len = 1;
        ListNode* tail = head;
        while(tail->next != NULL){
            tail = tail->next;
            len++;
        }

        // reduce unnecessary rotations
        k = k % len;
        if(k == 0){
            return head;
        }

        // new tail
        int steps = len - k - 1;
        ListNode* newTail = head;

        for(int i=0; i<steps; i++){
            newTail = newTail->next;
        }
        
        // New head is after new tail
        ListNode* newHead = newTail->next;

        // Break the list
        newTail->next = NULL;

        // Connect old tail to old head
        tail->next = head;

        return newHead;
    }
};