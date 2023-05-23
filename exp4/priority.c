#include<stdio.h> 
int main() 
{ 
int i,j=0,b,n,p[5],wt[5],bt[5],pr[5],tat[5]; 
int temp,te,t; 
float twt,ttat,awt,atat; 
printf("Enter the no of processes:\t"); 
scanf("%d",&n); 
printf("Enter the process numbers:\n"); 
for(i=0;i<n;i++) { 
scanf("%d",&p[i]); } 
for(i=0;i<n;i++) { 
printf("Enter the priority of %d process\t",i); 
scanf("%d",&pr[i]); 
printf("Enter the burst time of %d process\t",i); 
scanf("%d",&bt[i]); 
} 
for(i=1;i<n;i++) { 
for(j=0;j<=i;j++){ 
if(pr[i]<pr[j]) 
{ 
temp=pr[i]; 
pr[i]=pr[j]; 
pr[j]=temp; 
t=bt[i]; 
bt[i]=bt[j]; 
bt[j]=t; 
te=p[i]; 
p[i]=p[j]; 
p[j]=te; 
} 
} 
} 
wt[-1]=0; 
bt[-1]=0; 
for(i=0;i<n;i++) 
{ 
wt[i]=wt[i-1]+bt[i-1]; 
} 
for(i=0;i<n;i++) 
tat[i]=wt[i]+bt[i]; 
twt=0; 
ttat=0; 
for(i=0;i<n;i++) 
{ 
twt=twt+wt[i]; 
ttat=ttat+tat[i]; 
} 
atat=ttat/n; 
awt=twt/n; 
printf("\nProcess\twt\t tat\n"); 
for(i=0;i<n;i++) 
{ 
printf("\nP%d\t%d\t%d\n",p[i],wt[i],tat[i]); 
} 
printf("The average wt is %f\n",awt); 
printf("The average tat is %f\n",atat); 
return 1; 
}
