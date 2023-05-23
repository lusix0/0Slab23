#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#define BUFF_SIZE 10
char buffer[BUFF_SIZE];
int in =0, out =0;
#define SHARED 1
void *Producer(void *); /* the two threads */
void *Consumer(void *);
sem_t empty, full,mutex; /* the global semaphores */
int numIters;
int main(int argc, char *argv[]) 
{
 pthread_t pid, cid; /* thread ids */
 numIters = atoi(argv[1]);
 sem_init(&empty, SHARED, 1); /* sem empty = 1 */
 sem_init(&mutex, SHARED, 1); /* sem mutex = 1 */
 sem_init(&full, SHARED, 0); /* sem full = 0 */
 printf("main started\n");
 pthread_create(&pid, NULL, Producer, NULL);
 pthread_create(&cid, NULL, Consumer, NULL);
 pthread_join(pid, NULL);
 pthread_join(cid, NULL);
 printf("main done\n");
}
/* deposit 1, ..., numIters into the data buffer */
void *Producer(void *arg) 
{
 int produced;
 printf("Producer created\n");
 for (produced = 0; produced < numIters; produced++) 
{
 printf(" Producer produced : %d\n", produced);
 in = (in+1) % 10;
 sem_wait(&empty);
 sem_wait(&mutex);
 buffer[in] = produced;
 sem_post(&mutex);
 sem_post(&full);
 }
}
void *Consumer(void *arg) 
{
 int consumed;
 int data;
 printf("Consumer created\n");
for (consumed = 0; consumed < numIters; consumed++) 
{
 sem_wait(&full);
 sem_wait(&mutex);
 out = (out + 1) % 10;
 data = buffer[out];
 printf(" \tConsumer consumed : %d\n",data);
 sleep( 2 );
 sem_post(&mutex);
 sem_post(&empty);
 }
}
