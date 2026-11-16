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
    ListNode* getMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return true;
        ListNode* mid = getMid(head);
        ListNode* temp = mid -> next;
        mid -> next = Reverse(temp);
        ListNode* head1 = head;
        ListNode* head2 = mid -> next;
        while(head2 != nullptr){
            if(head1 -> val != head2 -> val) return false;
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
        
        return true;
    }
};