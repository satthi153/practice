#include <stdio.h>
#include <stdbool.h>

/*ring buffer structure*/
#define BUF_SIZE 10
typedef struct
{
    int buf[BUF_SIZE];
    int rd;
    int wr;
    bool full;
}ring_buf_t;

/*ring buffer APIs*/

bool isEmpty(ring_buf_t *rbuf)
{
   return (rbuf->wr == rbuf->rd);
}

bool isFull(ring_buf_t *rbuf)
{
    return ( ((rbuf->wr)%BUF_SIZE == (rbuf->rd)%BUF_SIZE) && (rbuf->wr != rbuf->rd) );
}

int put(ring_buf_t *rbuf, int data)
{

    if(isFull(rbuf))
        return -1;

    rbuf->buf[(rbuf->wr)%BUF_SIZE] = data;
    rbuf->wr++;
    return 0;
}

int get(ring_buf_t *rbuf, int *dataPtr)
{
    if(isEmpty(rbuf))
        return -1;

    *dataPtr = rbuf->buf[(rbuf->rd)%BUF_SIZE];
    rbuf->rd++;
    return 0;
}
                                                                             1,1           Top
    for(i=0;i<num;i++)
    {
        if(get(rbuf, &j) == -1)
        {
            printf("\nEMPTY: could read only %d items\n", i);
            break;
        }

        printf("%d:", j);
    }

    printf("\n");
    print_rd_wr("rd and wr after read\n", rbuf);

    printBuf("Buf after read\n", rbuf);

    printf("\n");

}

int main()
{
    ring_buf_t ring_buf = {0};
    ring_buf_t *rbuf = &ring_buf;

    // put 5 items
    write_to_rbuf(rbuf, 5);

    //write 6 more
    write_to_rbuf(rbuf, 6);


    //read 20 items
    read_from_rbuf(rbuf, 8);


    write_to_rbuf(rbuf, 5);
    read_from_rbuf(rbuf, 8);
    read_from_rbuf(rbuf, 8);
    write_to_rbuf(rbuf, 100);
    write_to_rbuf(rbuf, 5);
    read_from_rbuf(rbuf, 200);
    write_to_rbuf(rbuf, 100);
    return 0;
}
