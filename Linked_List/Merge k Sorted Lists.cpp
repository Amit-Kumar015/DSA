// https://leetcode.com/problems/merge-k-sorted-lists/description//

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
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while(l1 && l2){
            if(l1->val <= l2->val){
                curr->next = l1;
                l1 = l1->next;
            }
            else{
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        curr->next = l1 ? l1 : l2;

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }

    ListNode* divide(vector<ListNode*>& lists, int l, int r){
        if(l > r) return NULL;
        if(l == r) return lists[l];

        int mid = l + (r-l)/2;
        ListNode* left = divide(lists, l, mid);
        ListNode* right = divide(lists, mid+1, r);

        return merge(left, right);
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;  // Handle empty input
        
        int size = lists.size();
        
        return divide(lists, 0, size-1);
    }
};


// iterative
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
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while(l1 && l2){
            if(l1->val <= l2->val){
                curr->next = l1;
                l1 = l1->next;
            }
            else{
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        curr->next = l1 ? l1 : l2;

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;  // Handle empty input
        
        int size = lists.size();
        
        while(lists.size() > 1){
            vector<ListNode*> mergeList;
            for(int i=0; i<lists.size(); i+=2){
                ListNode* l1 = lists[i];
                ListNode* l2 = i+1 < lists.size() ? lists[i+1] : NULL;

                mergeList.push_back(merge(l1, l2)); 
            }
            lists = mergeList;
        }

        return lists[0];
    }
};