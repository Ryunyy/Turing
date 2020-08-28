#include "incl_test.h"
bool check_row(string row) {
    for(char ch : row) {
        if(ch == '*') {
            return 1;
        }
    }
    return 0;
}

TEST_CASE() {
    REQUIRE(check_row("*1000010010") == 1);
    REQUIRE(check_row("10000*10010") == 1);
    REQUIRE(check_row("1000010010*") == 1);
    REQUIRE(check_row("1000010010") == 0);
    REQUIRE(check_row("!@#$%^&*()") == 1);
    REQUIRE(check_row("weogewp-g+m=g43g438______") == 0);
}