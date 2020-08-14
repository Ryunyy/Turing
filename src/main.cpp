#include "incl.h"
#include "st.h"
extern void inst();
extern string s(string &str);
extern int r(vector<struct st> &rls, int N);
extern void string_processing(string &str);

int main() {
  inst();
  string str;
  vector<struct st> rls(100);
  s(str);
  cout << "Ваша строка:   " << str;
  int N = r(rls, 100);
  cout << "Вы ввели правила:  " << endl;
  for (int i = 0; i < N; i++)
    cout << rls[i].fp << " " << rls[i].es << " " << rls[i].ns << " "
         << rls[i].mv << " " << rls[i].np << endl;
  return 0;
}
