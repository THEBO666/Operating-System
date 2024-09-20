#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <stdlib.h>


void* Routine(void *args)
{
    
    int *x=(int*)args;
    //while(1)
    //{
        printf("I am thread1, pid: %d, ppid: %d, x=%d\n",getpid(),getppid(),++(*x));
        sleep(1);
    //}
}

int main()
{
    int *x= (int*)malloc(sizeof(int));
    pthread_t tid;
    pthread_create(&tid,NULL,Routine,(void*)x);
    
    //while(1)
    //{
        (*x)++;
        printf("I am main thread, pid: %d, ppid: %d, x=%d\n",getpid(),getppid(),*x);
        sleep(5);
    //}
    printf("%d\n",pthread_join(tid,NULL));
    return 0;
}