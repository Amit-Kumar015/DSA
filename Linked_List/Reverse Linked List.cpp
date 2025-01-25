// https://leetcode.com/problems/reverse-linked-list/description/

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
private:
    Node* reverse1(Node* head){
        if(head == NULL || head->next == NULL){
            return head;
        }

        Node* newHead = reverse1(head->next);

        head->next->next = head;
        head->next = NULL;

        return newHead;
    }

    void reverse(Node* &head, Node* curr, Node* prev){
        if(curr == NULL){
            head = prev;
            return;
        }

        Node* forw = curr->next;

        reverse(head, forw, curr);
        curr->next = prev;
    }

public:
    ListNode* reverseList(ListNode* head) {
        // Approach 1

        if(head == NULL){
            return NULL;
        }

        ListNode* prev = NULL;
        ListNode* forw = NULL;

        while(head != NULL){
            forw = head->next;
            head->next = prev;
            prev = head;
            head = forw;
        }

        return prev;

        // Approach 2

        Node* curr = head;
        Node* prev = NULL;

        reverse(head, curr, prev);
        return head;

        // Approach 3

        return reverse1(head);
    }
};