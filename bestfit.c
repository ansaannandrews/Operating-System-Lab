#include<stdio.h>

int main() {
    int mb, ps, i, j;

    printf("Enter the Number of Memory Blocks: ");
    scanf("%d", &mb);

    struct memory {
        int msize, alloc;
    } m[mb],temp;

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
    //sorting memory blocks in ascending order
    for(i = 0;i < mb-1;i++) {
        for(j = 0;j < mb-1;j++) {
            if(m[j].msize>m[j+1].msize)
		{
			temp = m[j];
	
			m[j] =m[j+1];
		
			m[j+1] = temp;
	
		}
	}
}
    

    for(i = 0; i < ps; i++) {  // for process
        int allocated = 0;
        for(j = 0; j < mb; j++) { // for memory
            if( m[j].alloc == 0 && p[i].psize <= m[j].msize) {
                m[j].alloc = p[i].flag;
                m[j].alloc = 1;
                printf("Process of size %d is allocated in Block of size %d\n", p[i].psize, m[j].msize);
                allocated = 1;
                break;
            }
        }
        if(!allocated) {
            printf("\nThere is no space for Process of size %d!!!!!\n", p[i].psize);
        }
    }
