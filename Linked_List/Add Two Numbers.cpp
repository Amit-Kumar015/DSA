// https://leetcode.com/problems/add-two-numbers/description/

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
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            int sum = l1->val + l2->val;
            ListNode* ans = new ListNode(sum%10);
            ListNode* temp = ans;
            int carry=sum/10;
            l1 = l1->next;
            l2 = l2->next;
    
            while(l1 || l2 || carry != 0){
                int v1 = l1 ? l1->val : 0;
                int v2 = l2 ? l2->val : 0;
    
                int sum = v1 + v2 + carry;
                int val = sum%10;
                carry = sum/10;
    
                temp->next = new ListNode(val);
                temp = temp->next;
    
                l1 = l1 ? l1->next : NULL;
                l2 = l2 ? l2->next : NULL;
            }
    
            return ans;
        }
    };