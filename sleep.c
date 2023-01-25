//
// Created by soso on 2023-01-25.
//
#include "kernel/types.h"
#include "user/user.h"

int main(int argn,char *argv[]){
    if(argn != 2){
        fprintf(2, "The number of input parameters must be 1");
        exit(1);
    }

    int sleepNum = atoi(argv[1]);
    printf("process in sleeping ... ...");
    sleep(sleepNum);
    exit(0);
}