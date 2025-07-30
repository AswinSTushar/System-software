#include<stdio.h>


int found (int f[], int w, int key) {
    for (int i = 0; i < w; i++)
        if (f[i] == key)
            return 1;
    return 0;
}


void fifo (int rs[], int n, int w) {
    int f[w];
    for (int i = 0; i < w; i++)
        f[i] = -1;
    
    int fp = 0, h;
    int hc = 0, fc = 0;
    printf("\n%10s%20s%20s\n\n", "Access", "Page in Memory", "Fault / Hit");
    for (int i = 0; i < n; i++) {
        if (found(f, w, rs[i])) {
            hc++;
            h = 1;
        }
        else {
            f[fp] = rs[i];
            fc++;
            fp = (fp + 1)% w;
            h = 0;
        }
        char fs[2*w];
        for (int j = 0, frp = 0; j < (2*w); j+=2, frp++) {
            if (f[frp] != -1)
                fs[j] = f[frp] + '0';
            else 
                fs[j] = '*';
            fs[j+1] = ' ';
        }
        if(h)
            printf("%10d%20s%20s\n", rs[i], fs, "Hit");
        else
            printf("%10d%20s%20s\n", rs[i], fs, "Falult");
    }
    printf("Hits: %d\n", hc);
    printf("Faults: %d\n", fc);
}


int main() {
    int n, w;
    printf("Enter length of Reference String and Frame Width: ");
    scanf("%d %d", &n, &w);
    int rs[n];

    printf("Enter reference String: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &rs[i]);
    fifo(rs, n, w);
    return 0;
}

