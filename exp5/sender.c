#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#define size 32
#include <string.h>
#include <stdlib.h>
int main()
{ int shmid; char s[100],*str;
printf("\nIpc message passing using shared memory sender");
shmid=shmget(60,size,IPC_CREAT|0666);
str=shmat(shmid,0,0);
printf("\nEnter the message to be sent: ");
scanf("%c",& *str);
strcpy(s,str);
printf("\nYour mesage has been sent\n");
return 0; }
