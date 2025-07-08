#include<stdio.h>
struct process{
	int pid;
	int bt;	
	int priority;
};


void sortByPriority(struct process p[],int n){
	
	for (int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(p[j].priority<p[i].priority){
				struct process temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
}


int main(){
	int n;
	printf("Enter number of processess... :");
	scanf("%d",&n);
	
	struct process p[n];
	
	for(int i=0;i<n;i++){
		p[i].pid=i+1;
		printf("Enter burst time & priority for process %d: ",p[i].pid);
		scanf("%d%d",&p[i].bt,&p[i].priority);
	}
	
	sortByPriority(p,n);
	int wt[n],tat[n];
	wt[0]=0;
	tat[0]=p[0].bt;
	float total_wt=0,total_tat=0;
	
	for(int i=1;i<n;i++){
		wt[i]=wt[i-1]+p[i-1].bt;
		tat[i]=wt[i]+p[i].bt;
	}
	printf("\nPID\tBT\tPRIORITY\tWT\tTAT\n");
	for(int i=0;i<n;i++){
		printf("%d\t%d\t%d\t\t%d\t%d\n",p[i].pid,p[i].bt,p[i].priority,wt[i],tat[i]);
		total_wt+=wt[i];
		total_tat+=tat[i];
	}
		printf("Average waiting time=%.2f",total_wt/n);
		printf("Average turnaround time=%.2f\n",total_tat/n);
	
	return 0;
}
