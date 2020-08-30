#include "incl_test.h"
int move(int point, st rule) {
    if(rule.mv == "r")
        point++;
    if(rule.mv == "l")
        point--;
    if(rule.mv == "n")
        point = point;
    return point;
}

TEST_CASE() {
    std::vector<st> rules;
    rules.resize(1);
    rules[0].fp = "q1";
    rules[0].es = "1";
    rules[0].ns = "0";
    rules[0].mv = "r";
    rules[0].np = "halt";
    REQUIRE(move(0, rules[0]) == 1);
    rules[0].fp = "q1";
    rules[0].es = "1";
    rules[0].ns = "0";
    rules[0].mv = "n";
    rules[0].np = "halt";
    REQUIRE(move(2, rules[0]) == 2);
    rules[0].fp = "q1";
    rules[0].es = "1";
    rules[0].ns = "0";
    rules[0].mv = "l";
    rules[0].np = "halt";
    REQUIRE(move(5, rules[0]) == 4);
    rules[0].fp = "q1";
    rules[0].es = "1";
    rules[0].ns = "0";
    rules[0].mv = "r";
    rules[0].np = "halt";
    REQUIRE(move(9999, rules[0]) == 10000);
    rules[0].fp = "q1";
    rules[0].es = "1";
    rules[0].ns = "0";
    rules[0].mv = "n";
    rules[0].np = "halt";
    REQUIRE(move(4325, rules[0]) == 4325);
    rules[0].fp = "q1";
    rules[0].es = "1";
    rules[0].ns = "0";
    rules[0].mv = "l";
    rules[0].np = "halt";
    REQUIRE(move(2222, rules[0]) == 2221);
}