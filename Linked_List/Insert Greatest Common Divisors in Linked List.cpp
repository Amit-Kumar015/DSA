// https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/

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
    int gcd(int a, int b){
        while(b > 0){
            int tmp = b;
            b = a%b;
            a = tmp;
        }
        return a;
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* tmp = head;
        while(tmp && tmp->next){
            ListNode* tmp2 = tmp->next;

            int m = tmp->val;
            int n = tmp2->val;
            int v = gcd(m, n);

            ListNode* node = new ListNode(v);
            tmp->next = node;
            node->next = tmp2;
            tmp = tmp2;
        }

        return head;
    }
};