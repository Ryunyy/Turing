#include "incl.h"

extern string replacement(vector<st> &rls, string &str, int i, int point);

void string_processing(string &str, vector<st> &rls)
 {
    int i  = 0, point = 0;
    string current_state = rls[0].fp;
    while(current_state != "halt"){
        if(current_state == rls[i].fp && str[point] == rls[i].es) {
            cout << replacement(rls, str, i, point) << endl;
        }
        else {
            i++;
        }
    }
 }