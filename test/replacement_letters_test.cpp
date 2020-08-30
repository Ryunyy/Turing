#include "incl_test.h"
string replacement(st rule, string str, int point) {
    if(rule.ns != "*") {
        str[point] = rule.ns[0];
    } else {
        str[point] = str[point];
    }

    return str;
}

TEST_CASE() {
    vector<st> rules;
    rules.resize(1);
    rules[0].fp = "q1";
    rules[0].es = "1";
    rules[0].ns = "0";
    rules[0].mv = "r";
    rules[0].np = "halt";
    REQUIRE(replacement(rules[0], "101", 0) == "001");
    REQUIRE(replacement(rules[0], "101", 2) == "100");
    rules[0].ns = "*";
    REQUIRE(replacement(rules[0], "10101010101", 8) == "10101010101");
    REQUIRE(replacement(rules[0], "q", 0) == "q");

}