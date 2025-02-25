#include<stdio.h>
#include<stdlib.h>

int mutex = 1,full = 0,empty =3,x = 0;

int wait(int s) {
     return --s;
}

int signal(int s) {
     return ++s;
}

void producer() {
     mutex = wait(mutex);
     empty = wait(empty);
     full = signal(full);
     x++;
     printf("Producer produce an Item......... %d\n",x);
     mutex = signal(mutex);
}

void consumer() {
     mutex = wait(mutex);
     full = wait(full);
     empty = signal(empty);
     printf("Consumer consume an Item......... %d\n",x);
     x--;
     mutex = signal(mutex);
}


int main () {
     int ch;
     printf("Operations:\n1. Producer\n2. Consumer\n3. Exit\n");
     while(1) {
          printf("\n\nChoose an Operation:\n");
          scanf("%d",&ch);
          
          switch(ch) {
          
               case 1:if((mutex == 1)&&(empty != 0)) {
                    producer();
               }
               else
                    printf("Buffer is Full\n");
               break;
               
               case 2:if((mutex == 1)&&(full != 0)) {
                    consumer();
               }
               else
                    printf("Buffer is Empty\n");
               break;
               
               case 3: printf("......Excited from Program......\n");
                    exit(0);
               break;
               
               default:printf("Invalid Choice\n");
               break;
          }
     }
}
            
               
