#include "incl.h"

extern string replacement(st s, string &str, int point);
extern int move(int point,st s);
extern void pointer(int point, string str);

void string_processing(string &str, vector<st> &rls) {
  int point = 0;
  string that_position = rls[0].fp;
  while (that_position != "halt") {
    int j = 0;
    for (st s : rls) {
      if (s.es == str[point] && s.fp == that_position) {
        replacement(s, str, point);
        pointer(point, str);
        point = move(point, s);
        that_position = s.np;
        j++;
      }
    }
      if(j){
        j = 0;
      } else {
        cout << endl << "rules for '" << str[point] << "' is not exist in " << that_position << " statement" <<  endl;
        break;
      }
  }
  return;
}
