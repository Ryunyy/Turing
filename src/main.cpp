#include "incl.h"
extern void inst();
extern void instr(string str);
extern void inrules();

int main() {
  string str;
  struct rls {
    char fp;
    char es;
    char ns;
    char mv;
    char np;
  };
  inst();
  instr(str);
  inrules();
  return 0;
}
