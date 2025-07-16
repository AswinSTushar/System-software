#include<stdio.h>
struct process{
	int pid,at,bt,rt,ct,tat,wt;
};

int main(){
int n,tq,time=0,completed=0;
float total_wt=0,total_tat=0;
printf("Enter number of processess : ");
scanf("%d",&n);
	struct process p[n];
	
	
	for(int i=0; i<n; i++){
		p[i].pid=i+1;
		printf("Enter Arrival time and burst time for processess P%d:\n ",i+1);
		scanf("%d%d",&p[i].at,&p[i].bt);
		p[i].rt=p[i].bt;
	}
	printf("Enter time quantum : ");
	scanf("%d",&tq);
	int done;
	do{
		done=1;
		for(int i=0; i<n; i++){
			if(p[i].rt>0&&p[i].at<=time){
			done=0;
			if(p[i].rt>tq){
				time+=tq;
				p[i].rt-=tq;
			}
			else{
			time+=p[i].rt;
			p[i].rt=0;
			p[i].ct=time;
			completed++;
			}
		}
	}
	if(done) time++;
	}while(completed<n);
	printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
	
		for(int i=0;i<n;i++){
			p[i].tat=p[i].ct-p[i].at;
			p[i].wt=p[i].tat-p[i].bt;
			total_tat+=p[i].tat;
			total_wt+=p[i].wt;
				
		printf("p%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
	
	}
		printf("Average waiting time=%.2f\n",total_wt/n);
		printf("Average turnaround time=%.2f\n",total_tat/n);
	
	return 0;
}
