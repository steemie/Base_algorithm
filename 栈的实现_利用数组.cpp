//利用数组实现栈 C++
#include <iostream>
using namespace std;

/* create stack use array  */

#define MAX_SIZE (10)

//use template
template<class T>
class stack
{
public:
    Stack();
    
    Stack(size_t maxElements);
    Stack(T data[],size_t maxElements);
    ~Stack();
    
    //push
    void Push();
    
    //pop
    T Pop();
    
    //return top element
    T Top();
    
    bool isEmpty();
    
    bool isFull();
    
    void Clear();
    
    size_t GetSize();
private:
    size_t top;
    T *array;   
    size_t maxSize;
};

template<class T>
Stack<T>::Stack():maxSize(MAX_SIZE),top(-1)
{
    array = new T[maxSize];
    if(array == NULL)
    {
        cout<<"new failed"<<endl;
    }
}

template<class T>
Stack<T>::Stack(size_t maxElements):maxSize(MAX_SIZE),top(-1)
{
    array = new T[maxSize];
}

template<class T>
Stack<T>::Stack(T data[],size_t maxElements):maxSize(MAX_SIZE),top(-1)
{
    array = new T[maxSize];
    
    for(size_t i = 0;i< maxSize;i++)
    {
        array[i] = data[i];
    }
    top += maxSize;
}

template<class T>
Stack<T>::~Stack()
{
    delete []array;    
}

template<class T>
bool Stack<T>::isFull()
{
    return top == maxSize - 1;
}

template<class T>
bool Stack<T> isEmpty()
{
    return top == -1;
}


template<class T>
void Stack<T>::Clear()
{
    while(top != -1)
    {
        top--;
    }
}

template<class T>
void Stack<T>::Push(T data)
{
    if (isFull)
    {
        throw runtime_error("Full stack");
    }
    else
    {
        top++;
        array[top] = data;
    }
    
}

template<class T>
void Stack<T>::Pop()
{
    if(isEmpty)
    {
        throw runtime_error("No elements in the stack");
        
    }
    else
    {
        T data = array[top];
        top--;
        return data;
    }
}

template<class T>
void Stack<T> Top()
{
    if(isEmpty)
    {
        throw runtime_error("No elements in the stack");
        
    }
    else
    {
        return array[top];
    }
}

template<class T>
size_t Stack<T> GetSize()
{
    return top+1;
}

int main()
{
	cout  << "test  stack(use array)" <<endl;
    try
    {
        int a[6] = {2,4,3};
        Stack<int> s(a,6);
        
        s.Pop();
        s.Push(5);
        
        for(int i = 0;i<6;i++)
        {
            cout<<s.Pop<<" ";
        }
        
    }
    catch(exception e)
    {
        cout<<e.what()<<endl;
    }
    
    cout<<endl;
    //system("pause");
	return 0;
}
