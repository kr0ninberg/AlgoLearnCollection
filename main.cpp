#include <gtest/gtest.h>

int main(int argc, char **argv) {

#ifdef TESTS
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
#else

    return 0;
#endif
}