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
    ListNode* ReverseList(ListNode*& head, ListNode*& curr, ListNode*& prev){
        if(curr == NULL) return prev;
        else{
            ListNode* forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
            return ReverseList(head, curr, prev);
        }
    }
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head -> next == NULL) return head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ReverseList(head, curr, prev);
        return prev;
    }
};