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
    ListNode* solve(ListNode* &list1, ListNode* &list2){
        if(list1 -> next == nullptr){
            list1 -> next = list2;
            return list1;
        }
        ListNode* prev = list1;
        ListNode* curr = prev -> next;
        ListNode* temp = list2;
        ListNode* next = temp -> next;
        while(curr != nullptr && temp != nullptr){
            if((temp -> val <= curr -> val) && (temp -> val >= prev -> val)){
                prev -> next = temp;
                next = temp -> next;
                temp -> next = curr;
                
                prev = temp;
                temp = next; 
            }
            else{
                prev = curr;
                curr = curr -> next;
                if(curr == nullptr){
                    prev -> next = temp;
                    return list1;
                }
            }
        }
        return list1;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        if(list1 -> val <= list2 -> val){
            return solve(list1, list2);
        }
        else{
            return solve(list2, list1);
        }
    }
};