 #include <fcntl.h> 
#include <stdio.h>
#include <stdlib.h>

void option();

 void main(int argc,char*argv[]){


 /* if(argc!=4){
    printf("\nErro de sintaxe, Comando deve ser ./copyfile arquivo1 arquivo2");
    exit(1);

  }
*/
  int fdold,fdnew,count;
  char buffer[2048]; 

  char toy[30] = argv[1];

  if(toy == "h" || toy == "--version"){

    options();

  }

  fdold=open(argv[2], O_RDONLY);

  if(fdold==-1){
    printf("Impossivel abrir arquivo primario");

  }

  fdnew=creat(argv[3],0666);

  if(fdnew==-1){
    printf("Impossivel criar arquivo secundario");

  }
  while((count=read(fdold,buffer,sizeof(buffer)))>0)

  {
    write(fdnew,buffer,count); //copia

  }

  exit(0);
}

void options(){

printf("-a, --archive   same as -dpR\n");
printf("-b, --backup    make backup before removal\n");
printf("-d, --no-dereference    preserve links\n");
printf("-f, --force     remove existing destinations, never prompt\n");
printf("-i, --interactive       prompt before overwrite\n");
printf("-l, --link      link files instead of copying\n");
printf("-p, --preserve  preserve file attributes if possible\n");
printf("-P, --parents   append source path to DIRECTORY\n");
printf("-r      copy recursively, non-directories as files\n");
printf("--sparse=WHEN   control creation of sparse files\n");
printf("-R, --recursive copy directories recursively\n");
printf("-s, --symbolic-link     make symbolic links instead of copying\n");
printf("-S, --suffix=SUFFIX     override the usual backup suffix\n");
printf("-u, --update    copy only when the SOURCE file is newer than the destination file or when the destination file is missing\n");
printf("-v, --verbose   explain what is being done\n");
printf("-V, --version-control=WORD      override the usual version control\n");
printf("-x, --one-file-system   stay on this file system\n");
printf("--help  display this help and exit\n");
printf("--version       output version information and exit.\n");

}