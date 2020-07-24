#include "incl.h"
extern void inst();
extern string s(string &str);

int main() {
  inst();
  string str;
  struct st {
    string fp;
    char es;
    char ns;
    char mv;
    string np;
  };
  st rules[100];
  s(str);
  return 0;
}
