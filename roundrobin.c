#include<stdio.h>
struct process{
	int pid,at,bt,rt,ct,tat,wt;
};

int main(){
int n,tq;
printf("Enter number of processess : ");
scanf("%d",&n);
	struct process p[n];
	printf("Enter Arrival time and burst time for processess :\n ");
	
	for(int i=0; i<n; i++){
		p[i].pid=i+1;
		printf("p%d",p[i].pid);
		scanf("%d%d",&p[i].at,&p[i].bt);
		p[i].rt=p[i].bt;
	}
	printf("Enter time quantum : ");
	scanf("%d",&tq);
	int time=0,completed=0;
	int done[n],idle;
	for(int j=0;j<n;j++) done[j]=0;
	
	while(completed<n){
		idle=1;
		for(int i=0;i<n;i++){
			if(p[i].at<=time&p[i].rt>0){
				idle=0;
				if(p[i].rt>tq){
				time+=tq;
				p[i].rt-=tq;	
				}
				else{
					time+=p[i].rt;
					p[i].rt=0;
					p[i].ct=time;
					done[i]=1;
					completed++;
				}
			}
		}
		if(idle) time++;
		
	}
	float total_tat=0,total_wt=0;
	for(int i=0;i<n;i++){
		p[i].tat=p[i].ct-p[i].at;
		p[i].wt=p[i].tat-p[i].bt;
		total_tat+=p[i].tat;
		total_wt+=p[i].wt;
	}
	printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
	for(int i=0;i<n;i++){
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
	
	}
		printf("Average waiting time=%.2f",total_wt/n);
		printf("Average turnaround time=%.2f\n",total_tat/n);
	
	return 0;
}
