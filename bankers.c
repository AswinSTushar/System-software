#include <stdio.h>
#define N 10
#define R 10
int main(){
	int n,r;
	int alloc[N][R],max[N][R],need[N][R],avail[R];
	int finish[N]={0},safeseq[N];
	printf("Enter number of process: ");
	scanf("%d",&n);
	printf("Enter number of resources types :");
	scanf("%d",&r);
	printf("Enter allocation matrix :\n");
	for(int i=0;i<n;i++)
		for(int j=0;j<r;j++)
			scanf("%d",&alloc[i][j]);
			
	printf("Enter maximum matrix :\n");
		for(int i=0;i<n;i++)
			for(int j=0;j<r;j++)
				scanf("%d",&max[i][j]);
				
				
	printf("Enter available resources :\n");
			for(int j=0;j<r;j++)
				scanf("%d",&avail[j]);
				
	for(int i=0;i<n;i++)
		for(int j=0;j<r;j++)
			need[i][j]=max[i][j]-alloc[i][j];
			
		printf("\nNeed matrix\n");
		for(int i=0;i<n;i++){
			printf("p%d:",i);
			for(int j=0;j<r;j++)
				printf("%d ",need[i][j]);
				printf("\n");
				}
					
	int count =0;
	while(count<n){
		int found=0;
		for(int i=0;i<n;i++){
			if(!finish[i]){
				int j;
				for(j=0;j<r;j++)
					if(need[i][j]>avail[j])
						break;
					if(j==r){
						for(int k=0;k<r;k++)
							avail[k]+=alloc[i][k];
							
							
						safeseq[count++]=i;
						finish[i]=1;
						found=1;
						}
					}
				}
				if(!found){
					printf("\n Sysrem is not in a safe state (Deadlock possible)\n");
					return 1;
					}
			
				}
			printf("\nSystem is in safe state\n Safe sequence..");
			
				for(int i=0;i<n;i++)
				printf("p%d->",safeseq[i]);
				printf("\n");
		return 0;
	}
