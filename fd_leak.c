#include <stdio.h>

#include <string.h>


/* FDй¶ 1
    �����ڴ�fd
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
/* FDй¶2    �󱨼�� 
    ���Ӻ����д��ļ���fd�������ȫ�ֱ���
    ���ⲿ�����ļ���ر��ļ�

    �����鹤���Ƿ����ִ��·���������������ⲿ���ڴ�й¶��
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