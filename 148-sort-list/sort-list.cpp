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
        ListNode* fast = head -> next;
        ListNode* slow = head;

        while(fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        return slow;
    }
    ListNode* Merge(ListNode* left, ListNode* right){
        if(left == nullptr) return right;
        if(right == nullptr) return left;

        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;

        while(left != nullptr && right != nullptr){
            if(left -> val < right -> val){
                temp -> next = left;
                temp = left;
                left = left -> next;
            }
            else{
                temp -> next = right;
                temp = right;
                right = right -> next;
            }

        }
        if(left != nullptr) temp -> next = left;
        else temp -> next = right;

        ans = ans -> next;
        return ans;
    }
    ListNode* sort(ListNode* &head){
        if(head == nullptr || head -> next == nullptr) return head;

        ListNode* mid = getMid(head);

        ListNode* left = head;
        ListNode* right = mid -> next;
        mid -> next = nullptr;

        left = sortList(left);
        right = sortList(right);

        ListNode* result = Merge(left, right);

        return result;
    }
    ListNode* sortList(ListNode* head) {
        return sort(head);
    }
};