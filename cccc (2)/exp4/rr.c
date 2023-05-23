 #include<stdio.h> 
int main() 
{ 
int ts,i,j=0,n,p[5],wt[5],bt[5],bt1[5],tat[5]; 
int t,tbt,et[15]; 
float twt=0,ttat=0,awt,atat; 
printf("Enter the no of processes:\t"); 
scanf("%d",&n); 
printf("Enter the process numbers:\n"); 
for(i=1;i<=n;i++) { 
scanf("%d",&p[i]); } 
for(i=1;i<=n;i++) { 
printf("Enter the burst time of %d process\t",i); 
scanf("%d",&bt[i]); 
} 

printf("Enter the time slice \t"); 
scanf("%d",&ts);
printf("Process\tBurst time\n"); 
for(i=1;i<=n;i++) { 
printf("%d\t%d\n",p[i],bt[i]); 
} 
tbt=0; 
for(i=1;i<=n;i++) 
{ 
tbt=tbt+bt[i]; 
bt1[i]=bt[i]; 
} 
printf("Total burst time\t %d\n",tbt); 
et[0]=0; 
j=1; 
while(tbt>0) 
{ 
for(i=1;i<=n;i++) 
{ 
if(bt[i]>0) 
{ 
t=bt[i]-ts; 
if(t>=0) 
{ 
bt[i]=bt[i]-ts; 
tbt=tbt-ts; 
et[j]=et[j-1]+ts; 
} 
else 
{ 
bt[i]=bt[i]-ts-t; 
tbt=tbt-ts-t; 
et[j]=et[j-1]+ts+t; 
} 
if(bt[i]==0) 
{ 
tat[i]=et[j]; 
} 
j++; 
} 
} 
} 
for(i=1;i<=n;i++) 
{ 
ttat=ttat+tat[i]; 
wt[i]=tat[i]-bt1[i]; 
twt=twt+wt[i];
} 
atat= ttat/n; 
awt=twt/n; 
printf("Average waiting time %f",awt); 
printf("Average turn around time%f\n",atat); 
return 1; 
} 
