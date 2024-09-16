#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

void* Routine(void *args)
{
    char *msg=(char*)args;
    while(1)
    {
        printf("I am %s, pid: %d, ppid: %d\n",msg,getpid(),getppid());
        sleep(1);
    }
}
int main()
{
    pthread_t tid;
    pthread_create(&tid,NULL,Routine,(void*)"thread1");
    while(1)
    {
        printf("I am main thread, pid: %d, ppid: %d\n",getpid(),getppid());
        sleep(5);
    }
    return 0;
}