#include "incl.h"
#include "st.h"

int r(vector<struct st> &rls, int N) {
  int j;
  string q = "";
  setlocale(LC_ALL, "RUS");
  cout << endl
       << "Введите правила обработки. Для завершения ввода введите 'stop':    "
       << endl;
  for (j = 0; j < N; j++) {
    cin >> q;
    if (q != "stop")
      rls[j].fp = q;
    else {
      N = j;
      break;
    }
    cin >> rls[j].es;
    cin >> rls[j].ns;
    cin >> rls[j].mv;
    cin >> rls[j].np;
  }
  return N;
}
