#include "incl.h"

string replacement(st s, string &str, int point) {
  if (s.ns != '*') {
    str[point] = s.ns;
  } else {
    str[point] = str[point];
  }

  return str;
}
