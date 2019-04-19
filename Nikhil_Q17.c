#include<stdio.h>
int main()
{
int i,n,p[10]={1,2,3,4,5,6,7,8,9,10},min,k=1,btime=0;
int bt[10],temp,j,at[10],wt[10],tt[10],sum=1,fsum=0,ct[10];
float wavg=0,tavg=0,tsum=0,wsum=0;
printf("Enter the No. of processes :\n");
scanf("%d",&n);
 
for(i=0;i<n;i++)
{
printf("Enter the Arrival time of p%d process :\n",i+1);
scanf("%d",&at[i]);
printf("Brust time of p%d process :\n",i+1);
printf("%d\n",bt[i]=2*at[i]);
}
 
/*Sorting According to Arrival Time*/
 
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(at[i]<at[j])
{
temp=p[j];
p[j]=p[i];
p[i]=temp;
temp=at[j];
at[j]=at[i];
at[i]=temp;
temp=bt[j];
bt[j]=bt[i];
bt[i]=temp;
}
}
}
 
for(j=0;j<n;j++)
{
btime=btime+bt[j];
min=bt[k];
for(i=k;i<n;i++)
{
if (btime>=at[i] && bt[i]<min)
{
temp=p[k];
p[k]=p[i];
p[i]=temp;
temp=at[k];
at[k]=at[i];
at[i]=temp;
temp=bt[k];
bt[k]=bt[i];
bt[i]=temp;
}
}
k++;
}
wt[0]=0;
sum=1;
ct[0]=1;
for(i=1;i<=n;i++)
{
	if(at[i-1]==0)
	  sum=sum+1;
sum=sum+bt[i-1];
ct[i-1]=sum;
tt[i]=ct[i-1]-at[i-1];
tsum=tsum+tt[i];
wt[i]=tt[i]-bt[i-1];
wsum=wsum+wt[i];
}
 
wavg=(wsum/n);
tavg=(tsum/n);
 
printf("******************************************************");
printf("\n\t\t\t\t\t\t\t RESULT:-");
printf("\n\t\t\t\t\t    Shortest Job First,Non-Preemptive\n\n");
printf("\n\t\t------------------------------------------------------------------------------------");
printf("\n\t\t|  Process  |\tBT\t|\tAT\t|\tWT\t|\tTAT\t|\tCT\t|" );
printf("\n\t\t------------------------------------------------------------------------------------");
for(i=0;i<n;i++)
{
printf("\n\t\t|  p%d\t    |\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t| ",p[i],bt[i],at[i],wt[i+1],tt[i+1],ct[i]);
}
printf("\n\t\t------------------------------------------------------------------------------------");
 
 printf("\n\n\n*************************************************************");
 printf("\n\t\t\t\t ..Order of execution according to Gantt chart..\n");

printf("\n");

printf("\t\t\t\t\t--------------\n\t\t\t\t\t");

for(i=0;i<n;i++)
{
printf("| Process[%d] |\n\t\t\t\t\t",p[i]);
}
printf("--------------\n\t\t\t\t\t");
printf("\n\n\n\nAVERAGE WAITING TIME : %f",wavg);
printf("\nAVERAGE TURN AROUND TIME : %f",tavg);
return 0;
}
