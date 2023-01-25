/*
 * Write a simple version of the UNIX find program: find all the files in a directory tree with a specific name. Your solution should be in the file user/find.c.
 *
 * 指定目录名的所有文件
 *
*/

#include "kernel/types.h"
#include "kernel/fcntl.h"
#include "kernel/stat.h"
#include "kernel/fs.h"
#include "user/user.h"


int main(int argc, char *argv[]){

    if(argc<3){
        printf("find: find <path> <fileName>\n");
        exit(0);
    }

    find(argv[1], argv[2]);
    exit(0);

}

