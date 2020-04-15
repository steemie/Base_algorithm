#include <iostream>
#include <vector>
using namespace std;

/* Ring_Buffer:use single list  */
// the import is malloc
struct Ring_Buffer_Packet
{
    unsigned char *buffer_ptr;
    unsigned short buffer_size;
    struct Ring_Buffer_Packet *next;
}

struct buffer_queue
{
    struct Ring_Buffer_Packet *p_head,*p_last;
    unsigned short max_size;
    unsigned short size;
}

//init
void buffer_queue_init(struct buffer_queue *queue,unsigned short max_size)
{
    queue->max_size = max_size;
    queue->p_head = NULL;
    queue->p_last = NULL;
}

//write data
unsigned short buffer_queue_write(struct buffer_queue *queue,unsigned char *pSrc,
                                    unsigned short wr_len)
{
    struct Ring_Buffer_Packet *packet = (struct Ring_Buffer_Packet*)malloc(sizeof(struct Ring_Buffer_Packet));
    
    if(queue->p_last == NULL)
    {
        queue->p_head = packet;
    }
    else
    {
        queue->p_last->next = packet;
    }
    
    //
    queue->p_last = packet;
    
    if(queue->size >= queue->max_size)
    {
        return 0;//error
    }
    
    //*wr_len is mutli ,not a point 
    packet->buffer_ptr = (unsigned char*)malloc(sizeof(unsigned char) * wr_len);
    memcpy(packet->buffer_ptr,pSrc,wr_len);
    pack->buffer_size = wr_len;
    packet->next = NULL;
    queue->size +=packet->buffer_size;
    
    return wr_len;
}

unsigned char buffer_queue_read(struct buffer_queue *queue,
                                unsigned char *dest,
                                unsigned short *rd_len)
{
    struct Ring_Buffer_Packet *packet;
    packet = queue->p_head;
    
    if(packet)
    {
        queue->p_head = queue->p_head->next;
        if(queue->p_head == NULL)
        {
            queue->p_last = NULL;
        }
        
        memcpy(dest,packet->buffer_ptr,packet->buffer_size);
        queue->size -= packet->buffer_size;
        *rd_len = packet->buffer_size;
        free(packet->buffer_ptr);
        free(packet);
    }
    else
    {
        *rd_len = 0;
    }
    
    return *rd_len;
    
}


int main()
{
	cout  << "test buffer queue" <<endl;
    //init write read
	return 0;
}
