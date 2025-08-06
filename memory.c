#include <stdio.h>


void firstfit(int proc[], int block[], int np, int nb) {
    int alloc[np];
    for (int i = 0; i < np; i++)
        alloc[i] = -1;

    printf("\n--- First Fit Allocation ---\n");

    for (int i = 0; i < np; i++) {
        for (int j = 0; j < nb; j++) {
            if (proc[i] <= block[j]) {
                block[j] -= proc[i];
                alloc[i] = j + 1; 
                break;
            }
        }
    }

    printf("%6s%9s%9s\n", "Pno", "Psize", "Block");
    for (int i = 0; i < np; i++) {
        if (alloc[i] == -1)
            printf("%6d%9d%9s\n", i + 1, proc[i], "NA");
        else
            printf("%6d%9d%9d\n", i + 1, proc[i], alloc[i]);
    }
}


void bestfit(int proc[], int block[], int np, int nb) {
    int alloc[np];
    for (int i = 0; i < np; i++)
        alloc[i] = -1;

    printf("\n--- Best Fit Allocation ---\n");

    for (int i = 0; i < np; i++) {
        int best = -1;
        for (int j = 0; j < nb; j++) {
            if (proc[i] <= block[j]) {
                if (best == -1 || block[j] < block[best])
                    best = j;
            }
        }
        if (best != -1) {
            block[best] -= proc[i];
            alloc[i] = best + 1;
        }
    }

    printf("%6s%9s%9s\n", "Pno", "Psize", "Block");
    for (int i = 0; i < np; i++) {
        if (alloc[i] == -1)
            printf("%6d%9d%9s\n", i + 1, proc[i], "NA");
        else
            printf("%6d%9d%9d\n", i + 1, proc[i], alloc[i]);
    }
}


void worstfit(int proc[], int block[], int np, int nb) {
    int alloc[np];
    for (int i = 0; i < np; i++)
        alloc[i] = -1;

    printf("\n--- Worst Fit Allocation ---\n");

    for (int i = 0; i < np; i++) {
        int worst = -1;
        for (int j = 0; j < nb; j++) {
            if (proc[i] <= block[j]) {
                if (worst == -1 || block[j] > block[worst])
                    worst = j;
            }
        }
        if (worst != -1) {
            block[worst] -= proc[i];
            alloc[i] = worst + 1;
        }
    }

    printf("%6s%9s%9s\n", "Pno", "Psize", "Block");
    for (int i = 0; i < np; i++) {
        if (alloc[i] == -1)
            printf("%6d%9d%9s\n", i + 1, proc[i], "NA");
        else
            printf("%6d%9d%9d\n", i + 1, proc[i], alloc[i]);
    }
}

int main() {
    int np, nb;
    printf("Enter number of processes and memory blocks: ");
    scanf("%d %d", &np, &nb);

    int proc[np], block[nb];
    int procbf[np], blockbf[nb]; 
    int procwf[np], blockwf[nb]; 

    printf("Enter size of processes:\n");
    for (int i = 0; i < np; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &proc[i]);
        procbf[i] = procwf[i] = proc[i];
    }

    printf("Enter size of memory blocks:\n");
    for (int i = 0; i < nb; i++) {
        printf("B%d: ", i + 1);
        scanf("%d", &block[i]);
        blockbf[i] = blockwf[i] = block[i];
    }

    firstfit(proc, block, np, nb);
    bestfit(procbf, blockbf, np, nb);
    worstfit(procwf, blockwf, np, nb);

    return 0;
}

