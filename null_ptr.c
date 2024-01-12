
/*
 空指针访问
*/
void null_ptr_1(void)
{
    char *heap_mem_100 = (char *)malloc(100);
    // [可能的]空指针访问
    heap_mem_100[10] = 10;
    if (heap_mem_100 == NULL)
        return;

    for (int i = 0; i < 20; i++)
        heap_mem_100[i] = i;
    free(heap_mem_100);
    // 访问已经释放的内存
    heap_mem_100[0] = 10;
    // 空指针访问
    heap_mem_100 = NULL;
    heap_mem_100[10] = 10;
    return;
}




/******************/
void null_ptr_test(void)
{
    null_ptr_1();
}