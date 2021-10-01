#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX_FILE_LENGTH  1000

char* getLine(char* loc, FILE* fileStream);
int checkStringMatch(char* toSearch, char* pattern);
void processfile(char* filename, char* pattern );

void main(int argc, char**argv){
            
    if(argc < 3){
        puts("Sintaxe incorreta, leitura correta: ./programa palavra arquivo.\n");
        exit(0);
    }

    char* pattern = argv[1];
    int i;
    
   for(i=2; i < argc; i++){
    
        char* filename = argv[i];
        processfile(filename, pattern);         
        
    }
}

void processfile(char* filename, char* pattern){
            
    FILE* f = fopen(filename, "r");

    if(!f){                
        fprintf(stderr, "Não é possivel abrir o arquivo %s.\n", filename);
        exit(0);
            
    }
            
    char* line = (char*)malloc(MAX_FILE_LENGTH*sizeof(char)); 
    int lineNum = 1;                         
    
    while(!feof(f)){                       
                   
        line = getLine(line, f);

        if(line){
                               
            if(checkStringMatch(line, pattern)){
                                            
                printf("%d %s", lineNum*1, line);
               
            }
            
            lineNum++;
            
        }
           
    }

    fclose(f);      
    free(line);
    
}

char* getLine(char* loc, FILE* fileStream){       
    return fgets(loc, MAX_FILE_LENGTH, fileStream);
}

int checkStringMatch(char* toSearch, char* pattern){       
    char* exists = strstr(toSearch, pattern);
    
    if(exists){      
        return 1;
            
    }    
return 0;

}