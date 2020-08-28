#include "incl_test.h"
int move(int point, vector<st> &rule, int i) {
    if(rule[i].mv == "r")
        point++;
    if(rule[i].mv == "l")
        point--;
    if(rule[i].mv == "n")
        point = point;
    return point;
}

TEST_CASE() {
    std::vector<st> rules;
    rules.resize(1);
    rules[0].fp = "q1";
    rules[0].es = "1";
    rules[0].ns = "0";
    rules[0].mv = "r"
    rules[0].np = "halt"
    REQUIRE(move(0, rules, 0) == 1);
}