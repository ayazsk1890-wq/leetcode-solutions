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
    ListNode* ReverseList(ListNode* curr){
        if(curr == NULL || curr -> next == NULL){
            return curr;
        }
        ListNode* chotaHead = ReverseList(curr->next);
        curr -> next -> next = curr;
        curr -> next = NULL;
        return chotaHead;
    }
    ListNode* reverseList(ListNode* head) {
        return ReverseList(head);
    }
};
