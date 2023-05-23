#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#define size 32
int main()
{ 
printf("\nipc message passing using shared memory-receiver");
int shmid; 
char *str;
shmid=shmget(60,size,IPC_CREAT|0666);
str=shmat(shmid,0,0);
printf("\nreceived message is....");
puts(str);
return 0; }

