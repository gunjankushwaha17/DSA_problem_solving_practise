/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;

        Node* curr = head;

        while (curr) {
            if (curr->child) {
                Node* tail = curr->child;
                while (tail->next) {
                    tail = tail->next;
                }
                tail->next = curr->next;
                if (curr->next) {
                    curr->next->prev = tail;
                }
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr;
            }
            curr = curr->next;
        }

        return head;
    }
};