#include <string.h>


/* �ڴ�й¶ 1
    �����������ڴ棬ָ�����ھֲ�����
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
/* �ڴ�й¶2    �󱨼�� 
    ���Ӻ����������ڴ棬����ָ��
    ���ⲿ�ͷ��ڴ�

    �����鹤���Ƿ����ִ��·���������������ⲿ���ڴ�й¶��
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