/*
 * Write a program that uses UNIX system calls to ''ping-pong'' a byte between two processes over a pair of pipes, one for each direction. The parent should send a byte to the child; the child should print "<pid>: received ping", where <pid> is its process ID, write the byte on the pipe to the parent, and exit; the parent should read the byte from the child, print "<pid>: received pong", and exit. Your solution should be in the file user/pingpong.c.
 *
 * 使用 UNIX 的系统调用实现;
 * ping pong 是一对管道的两个处理过程, 一来一回;
 * parent 发送 byte 到 child
 * child 打印 "<pid>: received ping", pid 表示当前程序的进程ID
 * child 写 byte 通过管道返回给 parent
 * parent 读到来自child的byte
 * */
#include "kernel/types.h"
#include "user/user.h"

int main() {

    int p1[2],p2[2];

    // 来回传输的字符数组: 一个字节
    char buffer[] = {'x'};

    // 传输字符数组的长度
    long length = sizeof(buffer);

    // 父进程写 p1 的数据缓存在名为管道的内存中
    pipe(p1);

    // 父进程写 p2 的数据缓存在名为管道的内存中
    pipe(p2);

    // 子进程
    if(fork() == 0){
        close(p1[1]);
        close(p2[0]);

        if(read(p1[0],buffer,length) != length){
            printf("a--->b read error!");
            exit(1);
        }

        printf("%d: received ping\n",getpid());

        if(write(p2[1],buffer,length) != length){
            printf("a<----b write error!");
            exit(1);
        }
        exit(0);
    }

    close(p1[0]);
    close(p2[1]);

    if(write(p1[1],buffer,length) != length){
        printf("a ----> b write error");
        exit(1);
    }

    if(read(p2[0],buffer,length) != length){
        printf("a <--- b read error !");
        exit(1);
    }

    printf("%d: received pong\n",getpid());
    wait(0);
    exit(0);
}
