// https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

// TC- O(N) SC- O(1)
class Solution {
    
    Node* middle(Node* head){
        Node* slow = head;
        Node* fast = head->next;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    Node* reverse(Node* head){
        Node* curr = head;
        Node* prev = NULL;
        Node* forw = NULL;
        
        while(curr != NULL){
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        
        return prev;
    }
    
  public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        if(head->next == NULL){
            true;
        }
        
        // step1 - get the middle of ll
        Node* mid = middle(head);
        
        // step2 - reverse ll afte middle
        Node* temp = mid->next;
        mid->next = reverse(temp);
        
        
        // step3 - compare both halves
        Node* head1 = head;
        Node* head2 = mid->next;
        
        while(head2 != NULL){
            if(head1->data != head2->data){
                return false;
            }
            
            head1 = head1->next;
            head2 = head2->next;
        }
        
        // step4 - repeat step2
        temp = mid->next;
        mid->next = reverse(temp);
        
        return true;
    }
};

// TC- O(N) SC- O(N)
class Solution
{
public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        vector<int> arr;
        Node *temp = head;

        while (temp != NULL)
        {
            arr.push_back(temp->data);
            temp = temp->next;
        }

        int s = 0, e = arr.size() - 1;
        while (s <= e)
        {
            if (arr[s] != arr[e])
            {
                return false;
            }
            s++;
            e--;
        }

        return true;
    }
};