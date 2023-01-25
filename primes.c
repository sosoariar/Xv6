/*
 * Created by soso on 2023-01-25.
 *
 * Write a concurrent version of prime sieve using pipes. This idea is due to Doug McIlroy, inventor of Unix pipes. The picture halfway down this page and the surrounding text explain how to do it. Your solution should be in the file user/primes.c.
 *
 * 使用管道编写一个prime sieve的并发版本
 *
 *
 * 将 2-35 中的素数打印出来
 * 素数: 大于1的自然数中，除了1和它本身以外不再有其他因数
 * */

#include "kernel/types.h"
#inlcude "user/user.h"

void func(int *input,int num) {

    if(num == 1){
        printf("prime %d\n",*input);
        return;
    }

    int p[2],i;
    int prime = *input;
    int temp;

    printf("prime %d\n",prime);
    pipe(p);
    if(fork() == 0){
        for(i = 0; i<num; i++){
            temp = *(input+i);
            write(p[1],(char*)(&temp),4);
        }
        exit(0);
    }

    close(p[1]);
    if(fork() == 0){
        int counter = 0;
        char buffer[4];
        while(read(p[0],buffer,4) != 0){
            temp = *((int *)buffer);
            if(temp % prime != 0){
                *input = temp;
                input += 1;
                counter++;
            }
        }

        func(input-counter,counter);
        exit(0);
    }
    wait(0);
    wait(0);
}

int main(){
    int input[34];
    int i=0;

    for(;i < 34; i++){
        input[i] = i+2;
    }

    func(input,34);
    exit(0);
}