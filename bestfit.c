#include<stdio.h>

void main() {
    int mb, ps, i, j;

    printf("Enter the Number of Memory Blocks: ");
    scanf("%d", &mb);

    struct memory {
        int size, alloc;
    } m[mb];

    printf("Enter the size of Each Memory Block:\n");
    for(i = 0; i < mb; i++) {
        scanf("%d", &m[i].size);
        m[i].alloc = 0;
    }

    printf("Enter the Number of Processes: ");
    scanf("%d", &ps);

    struct process {
        int psize, flag;
    } p[ps];

    printf("Enter the size of Each Process:\n");
    for(i = 0; i < ps; i++) {
        scanf("%d", &p[i].psize);
        p[i].flag = 0;
    }
    printf("\n\n");

    for(i = 0; i < ps; i++) {
        for(j = 0; j < mb; j++) {
            if(p[i].flag == 0 && m[j].alloc == 0 && p[i].psize <= m[j].size) {
                m[j].alloc = 1;
                p[i].flag = 1;
                printf("Process %d is allocated in %d block\n", p[i].psize, m[j].size);
                break;
            }
        }
        if(p[i].flag == 0) {
            printf("There is no space for %d process!!!!!\n", p[i].psize);
        }
    }
}

