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



}
