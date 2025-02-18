#include<stdio.h>

void main() {
    int mb, ps, i, j;

    printf("Enter the Number of Memory Blocks: ");
    scanf("%d", &mb);

    struct memory {
        int msize, alloc;
    } m[mb];

    printf("Enter the size of Each Memory Block:\n");
    for(i = 0; i < mb; i++) {
        scanf("%d", &m[i].msize);
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
        int allocated = 0;
        for(j = 0; j < mb; j++) {
            if(p[i].flag == 0 && m[j].alloc == 0 && p[i].psize <= m[j].msize) {
                m[j].alloc = 1;
                p[i].flag = 1;
                printf("Process of size %d is allocated in Block of size %d\n", p[i].psize, m[j].msize);
                allocated = 1;
                break;
            }
        }
        if(!allocated) {
            printf("\nThere is no space for Process of size %d!!!!!\n", p[i].psize);
        }
    }
}



/*#include<stdio.h>
void main() {

     int mb, ps , i, j;
     
     struct memory {
          int msize, alloc;
     }m[mb];
     
     struct process {
          int psize, flag;
     }p[ps];
     
     printf("Enter the Number of Memory Blocks: ");
     scanf("%d",&mb);
     printf("Enter the size of Each Memory Block:\n");
     for(i = 0; i < mb; i++) {
          scanf("%d",&m[i].msize);
          m[i].alloc = 0;
     }
     
     printf("Enter the Number of Process: ");
     scanf("%d",&ps);
     printf("Enter the size of Each Process:\n");
     for(i = 0; i < ps; i++) {
          scanf("%d",&p[i].psize);
          p[i].flag = 0;
     }
     
     for(i = 0; i < ps; i++) {
          for(j = 0; i < mb; i++) {
               if(p[i].flag == 0) {
                    if(p[i].psize <= m[j].msize) {
                         if(m[j].alloc == 1)
                              continue;
                         else {
                              m[j].alloc = 1;
                              p[i].flag == 1;
                              
                              printf("Process %d is allocated in %d Block\n",p[i].psize,m[j].msize);
                              }
                    }
               }
          }
    }
     
     for(i = 0; i < ps; i++) {
         if(p[i].flag == 0) {
              printf("There is no space for %d process\n",p[i].psize);
         }
   }
}   */
                              
                         
                    
