#include <string.h>


/* 内存泄露 1
    函数内申请内存，指针存放于局部变量
*/
void test_memleak_1(void)
{
    char *a;
    a = (char *)malloc(100);
    a[0] = 100;
    a[99] = 101;
    return;
}

/**************************/
/* 内存泄露2    误报检测 
    在子函数中申请内存，返回指针
    在外部释放内存

    考察检查工具是否具有执行路径跟踪能力，避免部分内存泄露误报
*/
char * g_memptr;

char *test_memleak_2_alloc_ptr(int size)
{
    char *a;
    a = (char *)malloc(size);
    if (a == NULL)
        return NULL;
    return a;
}

void test_memleak_2(void)
{
    char *mem_addr;
    g_memptr = test_memleak_2_alloc_ptr(203);
    for (int i = 0; i < 10; i++)
        g_memptr[i] = i;
    free(g_memptr);
    return;
}


/******************/
void test_memleak(void)
{
    test_memleak_1();
    test_memleak_2();
}