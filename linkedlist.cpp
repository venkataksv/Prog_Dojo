#include <iostream>


struct Node
{
    int data;
    Node *next;
};

int main()
{

    Node *head = nullptr;

    Node *n1 = new Node();
    Node *n2 = new Node();
    Node *n3 = new Node();

    Node *temp = head;

    n1->data = 10;
    n1->next = n2;

    n2->data = 20;
    n2->next = n3;

    n3->data = 30;
    n3->next = nullptr;

    head = n1;

    Node* current = head;

    while(current!=nullptr)
    {
        std::cout<<current->data<< " -> ";;
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;


    delete n1;
    delete n2;
    delete n3;

    return 0;

}