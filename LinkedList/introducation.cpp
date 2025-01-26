#include <iostream>
using namespace std;

struct Node {
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }


    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

int main(){

    Node* y = new Node(55,nullptr);
    cout<<y->data;
    return 0;
}