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
    ListNode* add(ListNode* l1, ListNode* l2){
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        int carry = 0;
        while(l1 != nullptr && l2 != nullptr){
            int sum = carry + l1 -> val + l2 -> val;
            int digit = sum % 10;

            InsertatTail(head, tail, digit);
            carry = sum / 10;
            l1 = l1 -> next;
            l2 = l2 -> next;
            
        }
        while(l1 != nullptr){
            int sum = carry + l1 -> val;
            int digit = sum % 10;

            InsertatTail(head, tail, digit);
            carry = sum / 10;
            l1 = l1 -> next;
        }
        while(l2 != nullptr){
            int sum = carry + l2 -> val;
            int digit = sum % 10;

            InsertatTail(head, tail, digit);
            carry = sum / 10;
            l2 = l2 -> next;
        }
        while(carry){
            int sum = carry;
            int digit = sum % 10;

            InsertatTail(head, tail, digit);
            carry = sum / 10;
        }
        return head;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = add(l1, l2);
        return ans;
    }
};