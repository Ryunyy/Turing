#include "incl.h"

extern string replacement(st rule, string &str, int point);
extern int move(int point, st rule);
extern void pointer(int point, string str);

void string_processing(string &str, vector<st> &rls) {
  int point = 0;
  string that_position = rls[0].fp;
  while (that_position != "halt") {
    int j = 0;
    bool star = false;
    for (st rule : rls) {
      if (rule.es[0] == str[point] && rule.fp == that_position) {
        replacement(rule, str, point);
        pointer(point, str);
        point = move(point, rule);
        that_position = rule.np;
        j++;
      }
      if (rule.es == "*" && rule.fp == that_position) {
        star = true;
      }
    }
    if (j) {
      j = 0;
    } else if (star == true) {
      for (st rule1 : rls) {
        if (rule1.es == "*" && rule1.fp == that_position) {
          replacement(rule1, str, point);
          pointer(point, str);
          point = move(point, rule1);
          that_position = rule1.np;
          star = false;
        }
      }
    } else {
      cout << endl
           << "rules for '" << str[point] << "' is not exist in "
           << that_position << " statement" << endl;
      break;
    }
  }
  return;
}
