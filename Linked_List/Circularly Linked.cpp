// https://www.naukri.com/code360/problems/circularly-linked_1070232?source=youtube&campaign=Lovebabbar_codestudio_26thjan&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar_codestudio_26thjan&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 
/*************************************************
        Following is the structure of class Node:
     
        class Node{
        public:
            int data;
            Node* next;
            
            Node(int data){
                this->data = data;
                this->next = NULL;
            }
            
        }
**************************************************/

bool isCircular(Node* head){
    // Approach 1

    // if(head == NULL){
    //     return true;
    // }


    // Node* p= head->next;
    // while(p != head && p != NULL){
    //     p= p->next;
    // }

    // return (p == head);


    // Approach 2
    
    if(head == NULL){
        return true;
    }

    map<Node*, bool> visited;

    Node* p= head;
    while(p != NULL){
        if(visited.find(p) != visited.end()){
            return true;
        }

        visited[p]=true;

        p=p->next;

        if(p==head){
            return true;
        }
    }

    return false;
}
