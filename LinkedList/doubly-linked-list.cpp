#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

public:
    Node(int data) : data(data), next(nullptr), prev(nullptr) {};
    Node(int data, Node *next) : data(data), next(next), prev(nullptr) {};
    Node(int data, Node *next, Node *prev) : data(data), next(next), prev(prev) {};
};

Node *convertToLL(vector<int> &arr)
{
    Node *head = new Node(arr.at(0));
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *node = new Node(arr.at(i));
        temp->next = node;
        node->prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *deleteHeadOfList(Node *head)
{
    if (!head)
        return head;

    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    free(temp);
    return head;
}

Node *deleteTailOfList(Node *head)
{
    if (!head || !head->next)
        return NULL;
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    free(temp->next->next);
    temp->next = NULL;
    return head;
}

Node *deleteKthNodeOfList(Node *head, int pos)
{
    if (!head)
        return NULL;

    int count = 0;
    Node *temp = head;
    while (temp->next != NULL)
    {
        count++;
        if (count == pos)
            break;
        temp = temp->next;
    }

    Node *prev = temp->prev;
    Node *next = temp->next;

    if (prev == NULL && next == NULL)
    {
        free(temp);
        return NULL;
    }
    else if (prev == NULL)
    {
        head = next;
        next->prev = NULL;
        temp->next = NULL;
        free(temp);
    }
    else if (next == NULL)
    {
        prev->next = NULL;
        temp->prev = NULL;
        free(temp);
    }
    else
    {
        prev->next = next;
        next->prev = prev;
        temp->next = NULL;
        temp->prev = NULL;
        free(temp);
    }

    return head;
}

int main()
{

    vector<int> arr = {45, 74, 55, 66};

    Node *head = convertToLL(arr);
    // head = deleteHeadOfList(head);
    // head = deleteTailOfList(head);
    head = deleteKthNodeOfList(head, 4);
    while (head != NULL)
    {
        // cout<<"--------------------------------"<<endl;
        // cout<<"PREV ADDRESS : "<<head->prev<<endl;
        // cout<<"CURRENT ADDRESS : "<<head<<endl;
        // cout<<"CURRENT DATA : "<<head->data<<endl;
        // cout<<"NEXT ADDRESS : "<<head->next<<endl;
        // cout<<"--------------------------------"<<endl;
        cout << head->data << " " << endl;
        head = head->next;
    }
}