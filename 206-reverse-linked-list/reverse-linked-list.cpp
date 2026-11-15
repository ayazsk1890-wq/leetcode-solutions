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
    ListNode* ReverseList(ListNode* curr, ListNode* prev){
        if(curr == NULL){
            return prev;
        }
        ListNode* forward = curr->next; 
        curr -> next = prev; 
        return ReverseList(forward, curr);
    }
    ListNode* reverseList(ListNode* head) {
        return ReverseList(head, NULL);
    }
};
