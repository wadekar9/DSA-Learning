#include <iostream>
using namespace std;

class Node {
    public:
    int val;
    Node* next;

    public:
    Node(int val1, Node* next1){
        val = val1;
        next = next1;
    }

    public:
    Node(int val1){
        val = val1;
        next = nullptr;
    }
};

Node* convertToLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* temp = head;

    for(int i=1;i<arr.size();i++){
        Node* newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = temp->next;
    }
    return head;
}

// function to remove head of linked list
Node* removeHead(Node* head){
    if(head==NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* removeTail(Node* head){
        if(head == NULL || head->next == NULL) return NULL;
        Node *temp = head;
        while(temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
        return head;
}

Node* removeKth(Node* head, int k){
        if(head == NULL) return NULL;

        if(k==1){
            Node *temp = head;
            head = head->next;
            free(temp);
            return head;
        }

        int count = 0;
        Node *temp = head, *prev = nullptr;

        while(temp != NULL) {
            count++;
            if(count == k){
                prev->next = prev->next->next;
                free(temp);
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        return head;
}

Node* removeValue(Node *head, int val){
    if(head==NULL) return NULL;

    if(val == head->val){
        Node *temp = head;
        head = head->next;
        return head;
    }

    Node *temp = head, *prev = NULL;
    while (temp != NULL){
        if(temp->val == val){
            prev->next = temp->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main(){

    vector<int> arr = {1,2,3,4,5,45,96,44};

    Node* head = convertToLL(arr);
    // head = removeHead(head);
    // head = removeTail(head);
    // head = removeKth(head, 3);
    head = removeValue(head, 96);
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}