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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || left == right){
            return head;
        }

        ListNode* prev = NULL;
        ListNode* curr = head;

        //move curr to left pos and prev jsut before left
        for(int i=1; i<left; i++){
            prev = curr;
            curr = curr->next;
        }

        // Save the node before the reversed portion
        ListNode* before = prev;
        ListNode* tail = curr;
        ListNode* nextNode = NULL;

        for (int i = 0; i <= right - left; i++) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // If left == 1, prev is the new head
        if (before == NULL) {
            head = prev;
        } 
        else {
            before->next = prev;
        }

        // Connect the end of reversed part
        tail->next = curr;

        return head;

    }
};