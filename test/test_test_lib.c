
#include "unittest.h"
#include <test_lib/api.h>

TEST_FUNC( test_lib ) {
    TEST_TRUE( test_lib_func() );
}

void SetupTests(void) {
    REG_TEST( test_lib );
}
