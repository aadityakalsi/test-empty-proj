
#include "unittest.h"
#include <header_only/hdronly.h>

TEST_FUNC( hdr_only ) {
    TEST_TRUE( hdronly_test() );
}

void SetupTests(void) {
    REG_TEST( hdr_only );
}
