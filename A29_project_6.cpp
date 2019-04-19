/*Design a scheduling program that is capable of scheduling many processes that 
comes in at some time interval and are allocated the CPU not more that 10 time units.
 CPU must schedule processes having short execution time first. 
 CPU is idle for 3 time units and does not entertain any process prior this time.
Scheduler must maintain a queue that keeps the order of execution of all the processes.
 Compute average waiting and turnaround time.*/

#include<stdio.h> 
int main() 
{ 
 
  int count,i,m,Time,remain,flag=0,T_quantum; // time quantum
  int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10]; 
  
  printf("Enter the number Total Process:\t "); 
  
  scanf("%d",&m); 
  
  remain=m; 
  for(count=0;count<m;count++) 
  { 
    printf("Enter Arrival Time and Burst Time for Process Process Number %d :",count+1); 
    scanf("%d",&at[count]); 
    scanf("%d",&bt[count]); 
    rt[count]=bt[count]; 
  } 
  printf("Enter Time Quantum:\t"); 
  scanf("%d",&T_quantum); 
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
  for(Time=0,count=0;remain!=0;) 
  { 
    if(rt[count]<=T_quantum && rt[count]>0) 
    { 
      Time+=rt[count]; 
      rt[count]=0; 
      flag=1; 
    } 
    else if(rt[count]>0) 
    { 
      rt[count]-=T_quantum; 
      Time+=T_quantum; 
    } 
    if(rt[count]==0 && flag==1) 
    { 
      remain--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,Time-at[count],Time-at[count]-bt[count]); 
      wait_time+=Time-at[count]-bt[count]; 
      turnaround_time+=Time-at[count]; 
      flag=0; 
    } 
    if(count==m-1) 
      count=0; 
    else if(at[count+1]<=Time) 
      count++; 
    else 
      count=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/m); 
  printf("Avg Turnaround Time = %f",turnaround_time*1.0/m); 
  
  return 0; 
}

