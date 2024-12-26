//local env & CI env but fail in sonar cloud
#include "CUnit/CUnit.h"
#include "CUnit/Automated.h"


#include "ft_printf.h"
#include <stdbool.h>

bool test_int();
void test_str();
void test_int_check();

bool test_int()
{
    int i = 0;
    while (i < 10)
    {
        if (ft_printf("result:%d", i) != printf("result:%d", i))
            return (false);
        i++;
    }
    return (true);
}

void test_int_check() {
  CU_ASSERT(test_int()==true)
  return;
}

int main(void)
{
    CU_pSuite testSuite = NULL;
    CU_initialize_registry();

    testSuite = CU_add_suite("JojoTestSuite", NULL, NULL);
    CU_add_test(testSuite, "Test Int", test_int_check);
    CU_automated_run_tests();
    CU_list_tests_to_file();
    CU_cleanup_registry();
    return 0;
}
