// https://www.naukri.com/code360/problems/middle-of-linked-list_973250?source=youtube&campaign=Lovebabbarcodestudio_24thJan&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio_24thJan&leftPanelTabValue=PROBLEM

/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* middle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

Node *findMiddle(Node *head) {
    // Approach 1

    if(!head){
        return NULL;
    }

    if(!head->next){
        return head;
    }
    
    int l=1;
    Node *curr= head;
    while(curr->next){
        l++;
        curr = curr->next;
    }

    curr=head;
    for(int i=0; i<l/2; i++){
        curr= curr->next;
    }

    return curr;

    // Approach 2

    return middle(head);    
}

