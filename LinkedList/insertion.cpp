#include <iostream>
using namespace std;

class Node {
    public:
    int val;
    Node *next;

    public:
    Node(int data, Node *ptr){
        val = data;
        next = ptr;
    }

    public:
    Node(int data){
        val = data;
        next = NULL;
    }
};

Node* convertToLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i=1;i<arr.size();i++){
        Node* node1 = new Node(arr[i]);
        temp->next = node1;
        temp = temp->next;
    }
    return head;
}

Node* addNode2Head(Node *head, int val){
    return new Node(val, head);
}

Node* addNode2Tail(Node *head, int val){
    Node* node = new Node(val);
    Node* temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = node;
    return head;
}

Node* addNodeKthPosition(Node *head, int val, int position){
    
    if(position == 1){
        return new Node(val, head);
    }

    int count = 0;
    Node* node = new Node(val), *temp = head, *prev = NULL;

    while (temp->next != NULL){
        count++;
        if(count == position){
            prev->next = node;
            node->next = temp;
            break;
        }   
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* insertBeforeValue(Node *head, int val, int position){
    if(head==NULL) return new Node(val);

    Node *node = new Node(val);
    Node *temp = head, *prev = NULL;

    if(temp->val==position){
        node->next = head;
        return node;
    }

    while (temp!=NULL){
        if(temp->val==position){
            prev->next = node;
            node->next = temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main(){

    vector<int> arr = {5,33,4,6,745,89,14,96,100,95};
    Node* head = convertToLL(arr);
    head = addNode2Head(head, 500);
    head = addNode2Tail(head, 1500);
    head = addNodeKthPosition(head, 2000, 3);
    head = insertBeforeValue(head, 900, 100);
    
    Node* temp = head;

    while (temp != NULL)
    {
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    
    return 0;
}