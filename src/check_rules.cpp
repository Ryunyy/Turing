#include "incl.h"

bool check_rules(vector<st> &rule) {
    if(rule[0].fp != "q1") {
        return 0;
    }
    for(st i : rule) {
        if(i.fp.length() > 10) {
            return 0;
        }
        if(i.es.length() > 1) {
            return 0;
        }
        if(i.ns.length() > 1) {
            return 0;
        }
    }
}