// https://leetcode.com/problems/reorder-list/description/

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

// recursive
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
        void reorderList(ListNode* head) {
            head = rec(head, head->next);
        }
    
        ListNode* rec(ListNode* root, ListNode* cur){
            if(!cur){
                return root;
            }
    
            root = rec(root, cur->next);
            if(!root){
                return NULL;
            }
    
            ListNode* temp = NULL;
            if(root == cur || root->next == cur){
                cur->next = NULL;
            }
            else{
                temp = root->next;
                root->next = cur;
                cur->next = temp;
            }
    
            return temp;
        }
    };

// looping
class Solution {
    public:
        void reorderList(ListNode* head) {
            if(!head->next){
                return;
            }
    
            ListNode* slow = head;
            ListNode* fast = head;
    
            while(fast && fast->next && fast->next->next){
                slow = slow->next;
                fast = fast->next->next;
            }
    
            ListNode* prev = NULL;
            ListNode* curr = slow->next;
            slow->next = NULL;
            ListNode* forw = NULL;
    
            while(curr){
                forw = curr->next;
                curr->next = prev;
                prev = curr;
                curr = forw;
            }
    
            ListNode* first = head;
            ListNode* second = prev;
    
            while(second){
                ListNode* temp1 = first->next;
                ListNode* temp2 = second->next;
                
                first->next = second;
                second->next = temp1;
    
                first = temp1;
                second = temp2;
            }
        }
    };