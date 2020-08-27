#include "incl.h"
extern bool r_insp(vector<struct st> &rls, int N);

int r(vector<struct st> &rls,int N) {
  int j, k = N;
  string q = "";
  setlocale(LC_ALL, "RUS");
  cout << endl
       << "Введите правила обработки. Для завершения ввода введите 'stop':    "
       << endl
       << endl;
z:
  N = k;
  for (j = 0; j < N; j++) {
    cin >> q;
    if (q != "stop")
      rls[j].fp = q;
    else {
      N = j;
      cout << endl;
      break;
    }
    cin >> rls[j].es;
    cin >> rls[j].ns;
    cin >> rls[j].mv;
    cin >> rls[j].np;
  }
  if (r_insp(rls, N))
    goto z;
  return N;
}
