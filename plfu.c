#include <stdio.h>

int main() {
    int p, f, i, j, k, count = 0;
    printf("Enter the number of Pages: ");
    scanf("%d", &p);
    int page[p];

    printf("Enter the Page Numbers: ");
    for (i = 0; i < p; i++) {
        scanf("%d", &page[i]);
    }

    printf("Enter the number of Frames: ");
    scanf("%d", &f);
    int frame[f];
    int RU[f];
    int time[f];

    for (i = 0; i < f; i++) {
        frame[i] = -1;
        RU[i] = 0;
        time[i] = 0;
    }

    j = 0;
    printf("\nPAGE\t\t\tFRAME\n");
    for (i = 0; i < p; i++) {
        int avail = 0;
        
        for (k = 0; k < f; k++) {
            if (frame[k] == page[i]) {
                avail = 1;
                RU[k]++;
                time[k] = i;
                break;
            }
        }

        printf("%d\t\t", page[i]);

        if (avail == 0) {
            int lfuIndex = 0;
            for (k = 1; k < f; k++) {
                if (RU[k] < RU[lfuIndex] || 
                    (RU[k] == RU[lfuIndex] && time[k] < time[lfuIndex])) {
                    lfuIndex = k;
                }
            }

            frame[lfuIndex] = page[i];
            RU[lfuIndex] = 1;
            time[lfuIndex] = i;

            count++;

            for (k = 0; k < f; k++) {
                if (frame[k] != -1) {
                    printf("%d\t", frame[k]);
                } else {
                    printf("-\t");
                }
            }
        } else {
            printf("HIT");
        }
        printf("\n");
    }

    printf("\nPage Fault = %d\n", count);
    return 0;
}

