// https://leetcode.com/problems/reverse-linked-list-ii/description/

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
        ListNode* reverseBetween(ListNode* head, int left, int right) {
            if(!head->next || left == right){
                return head;
            }
    
            ListNode* dummy = new ListNode(0, head);
            ListNode* front = dummy;
            ListNode* leftp = head;
    
            for(int i=0; i<left-1; i++){
                front = front->next;
            }
    
            leftp = front->next;
            ListNode* rightp = leftp;
    
            for(int i=0; i<right - left; i++){
                rightp = rightp->next;
            }
    
            ListNode* rear = rightp->next;
            rightp->next = NULL;
    
            ListNode* prev = NULL;
            ListNode* curr = leftp;
            ListNode* forw = NULL;
    
            while(curr){
                forw = curr->next;
                curr->next = prev;
                prev = curr;
                curr = forw;
            }
    
            front->next = prev;
            leftp->next = rear;
    
            return dummy->next;
        }
    };