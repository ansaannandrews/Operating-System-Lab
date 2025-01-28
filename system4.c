#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>

void main() {
     char *path,path1[10];
     struct stat *nfile;
     nfile = (struct stat*)malloc(sizeof(struct stat*));
     printf("Enter the File name: ");
     scanf("%s",path1);
     stat(path1,nfile);
     printf("User ID = %d\n",nfile->st_uid);
     printf("Block Size = %ld\n",nfile->st_blksize);
     printf("Last access time = %ld\n",nfile->st_atime);
     printf("Last modification time = %ld\n",nfile->st_mtime);
     printf("File size = %ld\n",nfile->st_size);
      printf("File permissions = %d\n",nfile->st_mode);
     printf("Number of hard links = %ld\n",nfile->st_nlink);
}
