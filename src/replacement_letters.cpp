#include "incl.h"

string replacement(st rule, string &str, int point) {
  if (rule.ns != "*") {
    str[point] = rule.ns[0];
  } else {
    str[point] = str[point];
  }

  return str;
}
