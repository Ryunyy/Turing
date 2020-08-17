#include "incl.h"

int move(int point, st rule) {
  if (rule.mv == "r")
    point++;
  if (rule.mv == "l")
    point--;
  if (rule.mv == "n")
    point = point;
  return point;
}
