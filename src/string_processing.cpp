#include "incl.h"

void string_processing(string &str, st* rules)
 {
    int i  = 0, point = 0;
    string current_state = rules[0].fp;
    while(current_state != "halt"){
        if(current_state == rules[i].fp && str[point] == rules[i].es);
    }
    
 }