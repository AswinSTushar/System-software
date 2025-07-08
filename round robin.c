#include<stdio.h>
struct process{
	int pid,at,bt,rt;
};

int main(){
int n,tq;
printf("Enter number of processess : ");
scanf("%d",&n);
	struct process p[n];
	printf("Enter Arrival time and burst time for processess :\n ");
	for(int i=0, i<n, i++){
		p[i].pid=i+1;
		printf("p%d",p[i].pid);
		scanf("%d%d",&p[i].at,&p[i].bt);
		p[i].rt=p[i].bt;
	}
	printf("Enter time quantum : ");
	scanf("%d",&tq);
	int time=0,completed=0;
	int done[n],i=0;
	for(int j=0;j<n;j++) done[j]=0;
	printf("\n Process execution order : \n ");
	while(completed<n){
		int executed=0;
		for(int j=0;j<n;j++){
			if(p[j].at<=time&p[j].rt>0){
				if(p[j].rt>tq){
					printf("p%d->",p[j].pid);
					p[j].rt-=tq;
					time+=tq;
				}
				else{
					printf("p%d->",p[j].pid);
					time+=p[j].rt;
					p[j].rt=0;
					done[j]=1;
					completed++;
				}
				executed=1;
			}
		}
		if(!executed)
		time++;
	}
	printf("End\n");
	return 0;
}
