/*************************************************************************
	> File Name: 27.main.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 13 Nov 2020 02:59:41 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ppchar char*
typedef char * pchar;

void output(int argc, char *argv[], char **env){
    for(int i = 0; env[i];i++){
        if(!strncmp(env[i], "USER=",5 )){
            if(!strcmp(env[i] + 5, "wxx")){
                printf("Welcome!!\n");
            }else{
                printf("you are not the user!\n");
                exit(0);
            }
        }
    }
    printf("argc = %d\n", argc);
    for(int i = 0; i < argc; i++){
        printf("%s\n",argv[i]);
    }
    for(int i = 0; env[i]; i++){
        printf("env[%d] = %s\n",i,env[i]);
    }
    return ;
}

int main(int argc, char *argv[], char **env){
    output(argc,argv,env);
    pchar p1,p2;
    ppchar p3,p4;
    printf("p1 = %lu, p2 = %lu\n",sizeof(p1), sizeof(p2));
    printf("p1 = %lu, p2 = %lu\n",sizeof(p3), sizeof(p4));
    return  0;
}
