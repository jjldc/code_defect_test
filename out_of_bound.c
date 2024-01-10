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




/******************/
void out_of_bound_test(void)
{
    out_of_bound_test_1();
    out_of_bound_test_2();
    out_of_bound_test_3();
}