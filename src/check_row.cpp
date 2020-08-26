#include "incl.h"

bool check_row(string &row) {
    for(char ch : row) {
        if (ch == "*") {
            return 0;
        }
    }
}