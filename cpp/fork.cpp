#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
 
/*
 * 总结
 * 1. fork生成子进程之后，复制了父进程的数据空间/堆/栈
 * 2. fork子进程如果不修改虚拟地址的内容，子进程和父进程指向相同的物理地址;子进程修改内容之后，通过写时复制技术,会重新复制物理地址的内容,两个虚拟地址开始指向不同的物理地址;但是虚拟地址还是一致的.
 * 参考:https://blog.csdn.net/xy010902100449/article/details/44851453
 */
int main()
{
    char str[6]="hello";
    char *ptr = (char *)malloc(10);
    strcpy(ptr, "yang");

    pid_t pid=fork();

    if(pid==0)
    {
        // fork的子进程,获取了父进程的数据空间/堆/栈,所以变量的地址(虚拟地址)也是一样的
        printf("子进程中str指向的首地址:%x\n",(void *)str);
        // linux为了提高 fork 的效率，采用了 copy-on-write 技术，fork后，这两个虚拟地址实际上指向相同的物理地址（内存页），只有任何一个进程试图修改这个虚拟地址里的内容前，两个虚拟地址才会指向不同的物理地址（新的物理地址的内容从原物理地址中复制得到））
        str[0]='b';
        printf("子进程中str=%s\n",str);
        printf("子进程中str指向的首地址:%x\n",(void *)str);

        ptr[0]='z';
        printf("子进程中ptr=%s\n",ptr);
        if(ptr != nullptr){
            free(ptr);
            ptr = nullptr;
        }
    }
    else
    {
        sleep(1);
        printf("父进程中str=%s\n",str);
        printf("父进程中str指向的首地址:%x\n",(void *)str);
        printf("父进程中ptr=%s\n",ptr);
        if(ptr != nullptr){
            free(ptr);
            ptr = nullptr;
        }
    }

    return 0;
}
