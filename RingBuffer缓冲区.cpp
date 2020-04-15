#include <iostream>
using namespace std;

/* circle buffer  */

#define BUFFER_SIZE (100)

typedef struct
{
    int head;
    int tail;
    int length;
    int buff[BUFFER_SIZE];
    
}Ring_BUFF;

Ring_BUFF ring_buff;
//init
void intitBuff(void)
{
    ring_buff.head = 0;
    ring_buff.tail = 0;
    ring_buff.length = 0;
    
}

//write data to buffer

bool writeBuffer(int data)
{
    // judge the length size
    if ( ring_buff.length >= BUFFER_SIZE)
    {
        //error
        return false;
        
    }
    
    //write
    ring_buff.buff[ring_buff.tail] = data;
    ring_buff.tail = (ring_buff.tail + 1)%BUFFER_SIZE;
    ring_buff.length++;
    return true;
    
}

bool readBuffer(int* pData)
{
    // just the length>0
    if(ring_buff.length <= 0)
    {
        return false;
        
    }
    
    //readBuffer
    *pData = ring_buff.buff[ring_buff.head];
    ring_buff.head = (ring_buff.head + 1) % BUFFER_SIZE;
    ring_buff.length--;
    
    return true;
    
    
    
}








int main()
{
	cout  << "test ringBuffer" <<endl;

    cout<<"write"<<endl;
    int data = 520;
    
    bool status = 0;
    status = writeBuffer(data);
    
    if(ring_buff.length > 0)
    {
        cout<<"length is:"<<ring_buff.length<<"data is:"<<ring_buff.buff[0]<<endl;
        
    }
    
    int readData;
    status |= readBuffer(&readData);
    
    
    cout<<"Now length is:"<<ring_buff.length<<endl;
    //system("pause");
	return status;
}
