#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_function(void *arg);

int i,j;

int main()
{

pthread_t a_thread;

pthread_create(&a_thread,NULL,thread_function,NULL);

pthread_join(a_thread,NULL);

printf("inside the main program \n");

for(i=10;i<15;i++)
{
printf("%d\n",i);
sleep(1);
}
}
void *thread_function(void *arg)
{
printf("Inside the thread\n ");

for(i=10; i<15;i++)
{
printf("%d\n",i);
sleep(1);
}
}