#include <iostream>
#define STACK_SIZE 100

template <typename T>
class Stack
{
    public:
        void pop();
        T top();
        size_t size();
        void push(T element);
        bool isEmpty();
        Stack<T>(){
            cnt = 0;
        };

    private:
        T array[STACK_SIZE];
        int cnt;


};

template <typename T>
void Stack<T>::push(T element)
{
    if(cnt>=STACK_SIZE)
    {
        std::cerr << "Error: Stack overflow" << std::endl;
    }
    array[cnt]=element;
    cnt++;
}

template <typename T>
bool Stack<T>::isEmpty()
{

    if(cnt == 0)
    {
        return true;
    }
    return false;

}

template <typename T>
void Stack<T>::pop()
{
    if(isEmpty())
    {
      throw std::out_of_range("pop() called on an empty stack");

    }
    cnt--;
}

template <typename T>
T Stack<T>::top()
{
    if(isEmpty())  
    {   
             throw std::out_of_range("top() called on an empty stack");

     }
    return array[cnt - 1]; 


}

template <typename T>
size_t Stack<T>::size()
{
    return cnt;
}
