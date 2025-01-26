#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;

    public:
    Node(int data) : data(data), next(nullptr), prev(nullptr) {};
    Node(int data, Node *next) : data(data), next(next), prev(nullptr) {};
    Node(int data, Node *next, Node *prev) : data(data), next(next), prev(prev) {};
};

Node* convertToLL(vector<int> &arr){
    Node* head = new Node(arr.at(0));
    Node* temp = head;
    for(int i=1;i<arr.size();i++){
        Node *node = new Node(arr.at(i));
        temp->next = node;
        node->prev = temp;
        temp = temp->next;
    }
    return head;
}

int main(){

    vector<int> arr = {6,9,23,45,74,55,30,98,75,324,12};

    Node *head = convertToLL(arr);
    while (head != NULL){
        cout<<"----------------"<<endl;
        cout<<"PREV ADDRESS : "<<head->prev<<endl;
        cout<<"CURRENT ADDRESS : "<<head<<endl;
        cout<<"CURRENT DATA : "<<head->data<<endl;
        cout<<"NEXT ADDRESS : "<<head->next<<endl;
        cout<<"----------------"<<endl;
        head = head->next;
    }
}