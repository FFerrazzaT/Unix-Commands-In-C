#include <fcntl.h> 
#include <stdio.h>
#include <stdlib.h>

void main(int argc,char*argv[]){

  if(argc!=2){ 
    printf("\nSintaxe deve ser ./list programa");
    exit(1);

  }
  
  int fdold,count;
  char buffer[2048]; 
  
  fdold=open(argv[1], O_RDONLY);
  if(fdold==-1){

    printf("Impossivel abrir arquivo");
    exit(1);

  }

  while((count=read(fdold,buffer,sizeof(buffer)))>0){

    printf("%s",buffer);
  }

  exit(0);
}