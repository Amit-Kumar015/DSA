// https://www.naukri.com/code360/problems/reverse-list-in-k-groups_983644?leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbar_codestudio_26thjan&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar_codestudio_26thjan&leftPanelTabValue=PROBLEM

/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

int getLength(Node *head) {
  int length = 0;

  while (head) {
    length++;
    head = head->next;
  }

  return length;
}

Node *kReverse(Node *head, int k) {
  // Write your code here.

  if (head == NULL) {
    return NULL;
  }

  Node *prev = NULL;
  Node *curr = head;
  Node *forw = NULL;
  int count = 0;

  while (curr != NULL && count < k) {
    forw = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forw;
    count++;
  }

  if (forw != NULL && getLength(forw) >= k) {
    head->next = kReverse(forw, k);
  } else {
    head->next = forw;
  }

  return prev;
}