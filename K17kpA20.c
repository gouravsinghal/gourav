#include<stdio.h>

struct process    
{
int arival_time,brust_time,waiting_time,turn_around_time,remainig_brust_time,process_id, flag,flag1, priority;
};
struct process p1[20];
int i,j,k,n,no,m;
float average_tat=0.0,average_wt=0.0;
int tbt=0;
void display()
{
printf("\nthe proc information:");
printf("\nprocess_id      arivaltime   brusttime");
for(i=0;i<n;i++)
{
printf("\n%d \t\t%d\t\t %d",p1[i].process_id,p1[i].arival_time,p1[i].brust_time);
}
}
int scheduling()
{
int loc,z,c;
int mini;
mini=99;
loc=-1;
for(c=0;c<n;c++)
{
for(z=0;z<n;z++)
{
	if(p1[c].priority>=p1[z+1].priority)
	{
     if(p1[z].remainig_brust_time>0&&p1[z].arival_time<=i&&p1[z].remainig_brust_time<mini)
    {
     mini=p1[z].remainig_brust_time;
     loc=z;
    }
    }
}
}
p1[loc].priority=1;
return loc;
}
void fdisplay()
{
	printf("\n\n the proc information:");
printf("\nproc_id  ari_time  brust_t  wait_t  turn_around_t  priority ");
for(i=0;i<n;i++)
{
printf("\n%d\t %d \t\t%d\t %d\t %d\t \t%d",p1[i].process_id,p1[i].arival_time,p1[i].brust_time,p1[i].waiting_time,p1[i].turn_around_time,p1[i].priority);
}
}

int main()
{
printf("*****************Welcome to dynamic changing priority**************");
int minimumv,locationv,minimums,locations;
printf("\nenter the number of processes:");
scanf("%d",&n);
printf("\nenter the proc information:");
for(i=0;i<n;i++)
{
p1[i].waiting_time=0;
p1[i].turn_around_time=0;
p1[i].flag=0;
p1[i].flag1=0;
p1[i].priority=0;
p1[i].process_id=i;
printf("\n enter the arival time of p[%d]",i);
scanf("%d",&p1[i].arival_time);
printf("\n enter the brust time of p[%d]",i);
scanf("%d",&p1[i].brust_time);
tbt+=p1[i].brust_time;
p1[i].remainig_brust_time=p1[i].brust_time;
}
printf("****************** The information of process*************");
display();
minimumv=p1[0].arival_time;
locationv=0;
//tells minimum arival time at process in locv
for(i=1;i<n;i++)
{
if(p1[i].arival_time<minimumv)
{
locationv=i; 
minimumv=p1[i].arival_time;
}
}
p1[locationv].priority=1;
 
//processes having same minimum  arival time at
for(i=0;i<n;i++)
{
if(p1[i].arival_time==minimumv)
{
p1[i].flag1=1; 
}
}

//gives process with minimum burst time
minimums=p1[0].brust_time;
locations=0;
for(i=0;i<n;i++)
{
if(p1[i].flag1==1&&p1[i].brust_time<minimums)
{
minimums=p1[i].brust_time; 
locations=i;
}
}
printf("\n******************gantt chart *************\n");
for(i=minimumv;i<tbt+minimumv;i++)
{

for(j=0;j<n;j++)
{
if(p1[j].remainig_brust_time>0 && p1[j].arival_time<=i)
{
p1[j].flag=1;
}
}
no=scheduling();


printf("%d--> p[%d]-->",i,p1[no].process_id);
p1[no].remainig_brust_time=p1[no].remainig_brust_time-1;
p1[no].priority=2;

for(k=0;k<n;k++)
{
if(p1[k].remainig_brust_time>0&&p1[k].arival_time<=i&&k!=no)
{
p1[k].waiting_time++;
}
}
}

printf("%d",tbt+minimumv);

for(i=0;i<n;i++)
{
average_wt+=p1[i].waiting_time;
}
average_wt=average_wt/n;
for(i=0;i<n;i++)
{
p1[i].turn_around_time=p1[i].waiting_time+p1[i].brust_time;
average_tat+=p1[i].turn_around_time;
}
average_tat=average_tat/n;
printf("\n\n average waiting time =%f, \n average turn around time =%f",average_wt,average_tat);
fdisplay();
}


