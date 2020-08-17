#include "incl.h"

extern string replacement(vector<st> &rls, string &str, int i, int point);
extern int move(int point, vector<st> &rls, int i);
extern void pointer(int point, string str);

void string_processing(string &str, vector<st> &rls) {
  int i = 0, point = 0;
  string that_position = rls[0].fp;
  while (that_position != "halt") {
    int j = 0;
    for (auto s : rls) {
      if (s.es == str[point] && s.fp == that_position) {
        j++;
      }
    }
      if(j){
        j = 0;
      } else {
        cout << "rules for '" << str[point] << "' is not exist in " << that_position << " statement" <<  endl;
        break;
      }
    if (that_position == rls[i].fp && str[point] == rls[i].es) {
      replacement(rls, str, i, point);
      pointer(point, str);
      point = move(point, rls, i);
      that_position = rls[i].np;
      i = 0;
    } else {
      i++;
    }
  }
  return;
}
