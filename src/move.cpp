#include "incl.h"

int move(int point, st s) {
  if (s.mv == 'r')
    point++;
  if (s.mv == 'l')
    point--;
  if (s.mv == 'n')
    point = point;
  return point;
}
