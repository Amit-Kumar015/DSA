#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        this->right = NULL;
        this->left = NULL;
    }
};

Node *insertIntoBST(Node *&root, int d)
{
    if (root == NULL)
        root = new Node(d);
    return root;
    if (d > root->data)
    {
        // insert in right part
        root->right = insertIntoBST(root->right, d);
    }
    else
    {
        // insert into left part
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                // queue still has some child nodes
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int minVal(Node* root){
    Node* temp = root;

    while(temp->left != NULL){
        temp = temp->left;
    }

    return temp->data;
}

int maxVal(Node* root){
    Node* temp = root;

    while(temp->right != NULL){
        temp = temp->right;
    }

    return temp->data;
}

Node* deleteFromBST(Node* &root, int val) {
    if(root == NULL) {
        return root;
    }

    if(root->data == val) {
        // 0 child case
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // 1 child case

        // left part
        if(root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // right part

        if(root->left == NULL && root->right != NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }


        // 2 child case

        if(root->left != NULL && root->right != NULL) {
            int min = minVal(root->right);
            root->data = min;
            root->right = deleteFromBST(root->right, min);
            return root;
        }
    }
    else if(root->data > val) {
        root->left = deleteFromBST(root->left, val);
        // return root;
    }
    else {
        root->right = deleteFromBST(root->right, val);
        // return root;
    }

    return root;
}

int main()
{
    Node *root = NULL;
    cout << "ENTER DATA TO ADD IN BST" << endl;
    takeInput(root);
    cout << "THE BST IS :" << endl;
    levelOrderTraversal(root);
    return 0;
}