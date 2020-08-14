#include "incl.h"

string replacement(vector<st> &rls, string &str, int i , int point) {
    str[point] = rls[i].ns;
    return str;
}