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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // find middle
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse LL
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(slow != NULL){
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
    
        // check palindrome
        ListNode* left = head;
        ListNode* right = prev;
        while(right != NULL){
            if(left->val != right->val){
                return false;
            }
            left = left->next;
            right = right->next;
        }

        return true;
    }
};