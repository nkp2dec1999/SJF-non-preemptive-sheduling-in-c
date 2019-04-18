#include<stdio.h>
void main()
{
int i,n,p[10]={1,2,3,4,5,6,7,8,9,10},min,k=1,btime=0;
int Burst_time[10],temp,j,Arival_time[10],wt[10],TAT[20],ta=1,sum=0;
float AWT=0,ATAT=0,Sum_TAT=0,Sum_WT=0;
printf("Enter the number of processes:\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
	printf("Arrival time of process[%d] :\n",i+1);
	scanf("%d",&Arival_time[i]);
	printf("Burst time of process[%d] :\n",i+1);
	Burst_time[i]=2*Arival_time[i];
	printf("%d\n",Burst_time[i]);
}
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		if(Arival_time[i]<Arival_time[j])
		{
			temp=p[j];
			p[j]=p[i];
			p[i]=temp;
			temp=Arival_time[j];
			Arival_time[j]=Arival_time[i];
			Arival_time[i]=temp;
			temp=Burst_time[j];
			Burst_time[j]=Burst_time[i];
			Burst_time[i]=temp;
		}
	}
}
wt[0]=0;//at start waiting time should be zero
//sum=1;
for(i=1;i<n;i++)
{
	sum=sum+Burst_time[i-1];
	wt[i]=sum-Arival_time[i];
	Sum_WT=Sum_WT+wt[i];
}
AWT=(Sum_WT/n);
for(i=0;i<n;i++)
{
	ta=ta+Burst_time[i];
	TAT[i]=ta-Arival_time[i];
	Sum_TAT=Sum_TAT+TAT[i];
}
ATAT=(Sum_TAT/n);


printf("\n\t\t\t\t\t\t       RESULT TABLE   ");
printf("\n\t\t\t\t\t      Shortest Job First,Non-Preemption    ");
printf("\n");
printf("\n\t\t\t\t\t-------------------------------------------------");
printf("\n\t\t\t\t\t|   PROCESS     |  BT   |  AT   |  WT   |  TAT  |");
printf("\n\t\t\t\t\t-------------------------------------------------");
for(i=0;i<n;i++)
{
	printf("\n\t\t\t\t\t| process[%d]\t|  %d\t|  %d\t|  %d\t|  %d\t|",p[i],Burst_time[i],Arival_time[i],wt[i],TAT[i]);
}
printf("\n\t\t\t\t\t-------------------------------------------------\n");
printf("\n ..Order of execution according to Gantt chart..\n");

printf("\n");

printf("\t\t\t\t\t--------------\n\t\t\t\t\t");

for(i=0;i<n;i++)
{
printf("| Process[%d] |\n\t\t\t\t\t",p[i]);
}
printf("--------------");
printf("\n\n\n\n AVERAGE TURNAROUND TIME: %f",AWT);
printf("\n AVERAGE TURN-AROUND-TIME : %f\n",ATAT);

}
