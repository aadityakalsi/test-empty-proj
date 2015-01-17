
#include <test-empty-proj/test_lib/export.h>
#include <test-empty-proj/unittest/unittest.h>

TEST_FUNC( test_lib ) {
    TEST_TRUE( test_lib_func() );
}

void SetupTests(void) {
    REG_TEST( test_lib );
}
