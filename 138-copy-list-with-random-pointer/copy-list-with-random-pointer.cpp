/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void InsertAtTail(Node* &head, Node* &tail, int val){
        Node* newNode = new Node(val);
        if(head == nullptr){
            head = newNode;
            tail = newNode;
            return;
        }
        tail -> next = newNode;
        tail = newNode;
    }
    Node* copyRandomList(Node* head) {
        Node* cHead = nullptr;
        Node* cTail = nullptr;
        Node* temp = head;

        while(temp != nullptr){
            InsertAtTail(cHead, cTail, temp->val);
            temp = temp -> next;
        }

        Node* oNode = head;
        Node* cNode = cHead;

        while(oNode != nullptr && cNode != nullptr){
            Node* nextO = oNode -> next;
            oNode -> next = cNode;
            oNode = nextO;
            
            Node* nextC = cNode -> next;
            cNode -> next = oNode;
            cNode = nextC;
        }
        temp = head;
        while(temp != nullptr) {
            if(temp->next != nullptr) {
                if(temp->random != nullptr) {
                    temp->next->random = temp->random->next;
                }
                else{
                    temp->next->random = nullptr;
                }
            }
            temp = temp->next->next;
        }
        oNode = head;
        cNode = cHead;

        while(oNode != nullptr && cNode != nullptr){
            oNode -> next = cNode -> next;
            oNode = oNode -> next;

            if(oNode != nullptr) cNode -> next = oNode -> next;
            cNode = cNode -> next;
        }
        return cHead;
    }
};