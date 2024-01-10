/*
 越界访问1
    全局变量数组，动态索引运行时越界
*/
int g_array_100[100];
void out_of_bound_test_1(void)
{
    for (int i = 0; i < 102; i++)
        g_array_100[i] = i;
    return;
}

/*
 越界访问2
    栈内局部变量，动态索引运行时越界
*/
void out_of_bound_test_2(void)
{
    int a[20] = {0};
    int b[20] = {0};
    int c[20] = {0};

    for (int i = 0; i < 30; i++)
        b[i] = c[i];
    return;
}


/*
 越界访问3
    函数内申请动态内存，越界访问
*/
void out_of_bound_test_3(void)
{
    char *heap_mem_100 = (char *)malloc(100);
    if (heap_mem_100 == NULL)
        return;

    for (int i = 0; i < 103; i++)
        heap_mem_100[i] = i;
    return;
}


/*
 越界访问4
    在A函数内申请动态内存，B函数内根据参数越界访问
*/
char *g_array_50 = NULL;
char *alloc_g_array_50(void)
{
    return (char *)malloc(50);
}

char get_array_member(int idx)
{
    return g_array_50[idx];
}

void out_of_bound_test_4(void)
{
    char res;
    g_array_50 = alloc_g_array_50();
    // 越界访问在A函数中申请的50字节数组
    g_array_50[100] = 1;
    // 通过函数参数访问50字节数组
    res = get_array_member(0);
    res = get_array_member(100);
    return;
}

/******************/
void out_of_bound_test(void)
{
    out_of_bound_test_1();
    out_of_bound_test_2();
    out_of_bound_test_3();
    out_of_bound_test_4();
}