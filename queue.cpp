#include <iostream>
#define QUEUE_SIZE 1000

class Queue
{

    public:
        int front();
        void enqueue(int element);
        void deque();

        bool isEmpty();
        size_t size();
        Queue() : index(0), frontIndex(0), rearIndex(-1){};
    private:
        int index;
        int frontIndex;
        int rearIndex;
        int arr[QUEUE_SIZE];

};

bool Queue::isEmpty()
{
    return index <= 0;
}


void Queue::enqueue(int element)
{
    if(index == QUEUE_SIZE)
    throw std::out_of_range("push failed as full queue");
    rearIndex = (rearIndex + 1) % QUEUE_SIZE ;
    arr[index] = element;
    index++;

}

int Queue::front()
{
    if(!isEmpty())
        return arr[frontIndex];
    throw std::out_of_range("front() can't access element");
}


void Queue::deque()
{
    if(isEmpty())
    {
        throw std::out_of_range("dequeu() can't access element");

    }
    frontIndex = (frontIndex + 1) % QUEUE_SIZE;
    index--;
}

int main()
{

}