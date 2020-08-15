#include "incl.h"

int move(int point, vector<st> &rls, int i) {
  if (rls[i].mv == 'r')
    point++;
  if (rls[i].mv == 'l')
    point--;
  if (rls[i].mv == 'n')
    point = point;
  return point;
}
