#include <stdio.h>

#include <string.h>


/* FD泄露 1
    函数内打开fd
*/
void test_fdleak_1(void)
{
    int fd;
    fd = open("/dev/zero", O_RDONLY);
    if (fd == -1)
    {
        printf("error open file\n");
        return;
    }
    write(fd, "123", 3);
    // close(fd);
    return;
}

/**************************/
/* FD泄露2    误报检测 
    在子函数中打开文件，fd句柄存于全局变量
    在外部操作文件后关闭文件

    考察检查工具是否具有执行路径跟踪能力，避免部分内存泄露误报
*/
int g_fd;

int test_fdleak_2_openfile(char * filename)
{
    int fd;
    fd = open(filename, O_RDWR);
    if (fd != -1)
        return fd;
    else
        return -1;
}

void test_fdleak_2(void)
{
    char buf[100];
    g_fd = test_fdleak_2_openfile("/tmp/testfile");
    read(g_fd, buf, 100);
    close(g_fd);
    return;
}


/******************/
void test_fdleak(void)
{
    test_fdleak_1();
    test_fdleak_2();
}