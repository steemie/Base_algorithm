/*
由于栈是一个表，所以实现表的方法都可以用于实现栈，一种是数组，一种是链表，
使用数组需要提前声明一个已知大小的数组，如果声明过大，会造成空间的浪费，
所以节省的做法是使用链表
*/
#include <iostream>
using namespace std;

/* create stack use list  */

//add typedef then can use Stack by directly;
typedef struct Node
{
    int data;
    Stack* next;
}Stack;

// create stack
Stack* createStack()
{
     Stack* S = (Stack*)malloc(sizeof(Stack));
     if(S == NULL)
     {
         cout<<"create failed"<<endl;
         return NULL;
     }
     
     S->next = NULL;
     return S;
}

//judge the stack is NULL
bool isEmpty(Stack* S)
{
    return S->next == NULL;
}

//push stack(input)
void push(Stack* S,int e)
{
    if(S != NULL)
    {
        Stack* ptr = (Stack*)malloc(sizeof(Stack));
        ptr->data = e;
        ptr->next = S->next;
        S->next = ptr; //next was override 
    }
    else
    {
        cout<<"Create Stack first"<<endl;
    }
    
    return ;
    
}

//pop (output)
void (Stack* s)
{
    if(s == NULL)
    {
        return; 
    }
    
    if(!isEmpty(s))
    {
        //not understand follow 
        Stack *ptr = s->next;
        s->next = ptr->next; //next next
        free(ptr);
    }
    else
    {
        cout<<"stack is empty"<<endl;
        
    }
}

//clear stack
void makeEmpty(Stack *S)
{
    Stack* ptr;
    if(S==NULL)
    {
        cout<<"Go to create stack"<<endl;
        return;
    }
    while(S->next !=NULL)
    {
        ptr = S->next;
        S->next = ptr->next;
        free(ptr);
    }
}

//return the top element of the stack
int top(Stack *S)
{
    if(S==NULL)
    {
        cout<<"Go to create stack"<<endl;
        return;
    }
    
    if(!isEmpty())
    {
        return S->next->data;
    }
    else
    {
        cout<<"is empty"<<endl;
        return 0;
    }
    
}

// destroy stack
void destroyStack(Stack S)
{
    if(S!=NULL)
    {
        makeEmpty(S);
        Stack* ptr = S;
        free(ptr);
        S = NULL;
    }
}


int main()
{
	cout  << "test  stack(use list)" <<endl;
    
	return 0;
}
