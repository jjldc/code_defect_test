extern void test_memleak(void);
extern void test_fdleak(void);
extern void out_of_bound_test(void);
extern void null_ptr_test(void);

int main(void)
{
    test_memleak();
    test_memleak();
    test_memleak();
    test_fdleak();
    out_of_bound_test();
    null_ptr_test();
    return 0;
}
