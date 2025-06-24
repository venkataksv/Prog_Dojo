#include <iostream>


class Node{

    public:
    int data;
    Node* next;

    Node(){    
        next = nullptr;
    }

    Node(int d){
        data = d;
        next = nullptr;
    }

};

int main()
{

    Node *head = new Node();

    Node *n1 = new Node(2);
    Node *n2 = new Node(4);
    Node *n3 = new Node(5);
    Node *n4 = new Node(6);

    head = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    std::cout<<"Before reversing: "<<std::endl;

    Node* tem = head;
    while(tem!=nullptr)
    {
        std::cout<<tem->data<<std::endl;
        tem=tem->next;
    }


    Node *prev;
    prev = nullptr;
    Node *current = head;
    while(current!=nullptr)
    {
        Node *temp;
        temp = current->next;
        current->next  =  prev;
        prev = current;
        current = temp;
    }
    head = prev;

    std::cout<<"After reversing: "<<std::endl;

    Node* temp = head;
    while(temp!=nullptr)
    {
        std::cout<<temp->data<<std::endl;
        temp=temp->next;
    }



    return 0;
}