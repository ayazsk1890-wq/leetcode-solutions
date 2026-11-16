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
    ListNode* Reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while(curr != nullptr){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void InsertatTail(ListNode* &head, ListNode* &tail, int digit){
        ListNode* temp = new ListNode(digit);
        if(head == nullptr){
            head = temp;
            tail = temp;
            return;
        }
        else{
            tail -> next = temp;
            tail = temp;
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;

        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        while(l1 != nullptr || l2 != nullptr || carry){
            int val1 = 0;
            if(l1 != nullptr) val1 = l1 -> val;
            int val2 = 0;
            if(l2 != nullptr) val2 = l2 -> val;

            int sum = carry + val1 + val2;
            int digit = sum % 10;

            InsertatTail(head, tail, digit);
            carry = sum / 10;

            if(l1 != nullptr) l1 = l1 -> next;
            if(l2 != nullptr) l2 = l2 -> next;
            
        }
        return head;
    }
};