#include "incl.h"
extern void inst();
extern string s(string &str);
extern int r(vector<struct st> &rls, int N);
extern void string_processing(string &str, vector<st> &rls);

int main() {
  inst();
  string str;
  vector<struct st> rls(100);
  s(str);
  cout << "Ваша строка:   " << str;
  r(rls, 100);
  string_processing(str, rls);
  return 0;
}
