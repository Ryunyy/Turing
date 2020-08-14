#include "incl.h"
extern void inst();
extern string s(string &str);
extern void string_processing(string &str);

int main() {
  inst();
  string str;
  st rules[100];
  s(str);
  string_processing(str);
  return 0;
}
