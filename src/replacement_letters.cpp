#include "incl.h"

string replacement(vector<st> &rls, string &str, int i , int point) {
    if(rls[i].ns != '*') {
        str[point] = rls[i].ns;
    }
    else
    {
        str[point] = str[point];
    }
    
    return str;
}