#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SYM 50
#define BUF 20


typedef struct symtab{
	char tab[20];
	int addr;
}stab;



void run (FILE* optab,FILE* inter,FILE* symtab,char opcode[],char label[],char op[],int* start,int* locctr){
	if (strcmp(opcode="START")==0);
	
	typedef struct optab{
		char opnd[20];
		int addr;
	}optb;
	
	
	
int st_cnt=0,otsze=0,start=0,locctr=0;
stab st[MAX_SYM];
optb otab[MAX_SYM];


void run (FILE* inter,char opcode[],char label[],char op[]){
	if(strcmp(opcode,"START")==0){
		start=locctr=(int)strtol(op,NULL,16);
		fprint(inter,"%x\t%s\t%s\n",start,label,opcode,op);
		return;
	}
	
	
	
in inc;
if(strcmp(label,"**")){
	int found=0;
	for(int i=0;i<st_cnt;i++){
		if(!strcmp(st[i].lab,label)){
			found=1;
		}
	}
	if(found){
		printf("Symbol %s Already Declared!!!\n");
		exit(1);
	}
	else{
		strcpy(st[st_cnt].lab,label);
		st[st_cnt++].addr=locctr;
	}
}


if(!strcmp(opcode,"BYTE"))
	inc=strlen(op);
	
	else if(!strcmp(opcode,"WORD"))
	inc=3;
	
	else if(!strcmp(opcode,"RESB"))
	inc=(int)strtol(op,NULL,10);
	
	else if(!strcmp(opcode,"RESW"))
	inc=3*(int)strtol(op,NULL,10);
	
	else{
	int found=0;
	for(int i=0;i<otsize;i++){
		if(!strcmp(opcode,otab[i].opnd)){
			found=1;
			break;
		}
	}
	
	
	if(found)
		inc=3;
	else if(!strcmp(opcode,"END"))
		inc=0;
	else{
		printf("OPCODE %s NOT FOUND!!!\n",opcode);
		exit(1);
	}
	}
	
	
	fprintf(inter,"%x\t%s\t%s\t%s\n",locctr,label,opcode,op);
	locctr+=inc;
	}
	
	
	
int main(){
	FILE* src= fopen("input.sic","r");
	FILE* optab= fopen("optab","r");
	FILE* inter= fopen("intermediate","w");
	FILE* symatb= fopen("symtab","w+");
	
	if(!src){
	FILE* inter= fopen("intermediate.sic","w");
	FILE* symatb= fopen("symtab","w");
	if(!src  ||  !optab   ||   !inter  ||  !symtab ){
		printf("Could not oprn file...\n");
		retrurn 0;
	}
	
	
	char label[BUF],opcode[BUF],op[BUF];
	int start=0,locctr=0;
	printf("SIC program.....\n");
	printf("%10s%10s%10s/n","LABEL","OPCODE","OPERAND");
	
	
	int opint;
	while(fsacnf (optab,"%s\t%d",opcode,&opint)>0){
	strcpy(otab[otsize],opnd,opcode);
	otab[otsize++].addr=opint;
	}
	
	
	printf("Implementing pass 1....\n Intermediate file....\n");
	printf("%10s%10s%10s%10s\n","ADDRESS","LABEL","OPCODE","OPERAND");
	do{
		
	}
	}	
}
}
}
