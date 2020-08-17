#include "incl.h"

bool r_insp(vector<struct st> &rls, int N) {
  int i = 0;
  while ((rls[i].fp != "q1") && (i < N))
    i++;
  if (i == N) {
    cout << endl
         << "Нет положения 'q1'! Пожалуйста, введите правила корректно!" << endl
         << endl;
    return 1;
  }
  i = 0;
  while ((rls[i].np != "halt") && (i < N)) {
    i++;
    if (i == N) {
      cout << endl
           << "Нет положения 'halt'! Пожалуйста, введите правила "
              "корректно!"
           << endl
           << endl;
      return 1;
    }
  }
  for (i = 0; i < N; i++) {
    int j = 0;
    if (rls[i].np == "halt")
      i++;
    while ((rls[j].fp != rls[i].np) && (j < N))
      j++;
    if ((j == N) && (rls[j - 1].fp != rls[i].np) && (i < N)) {
      cout << endl
           << "Нет положения '" << rls[i].np
           << "'! Пожалуйста, введите правила "
              "корректно!"
           << endl
           << endl;
      return 1;
    }
  }
  for (i = 0; i < N; i++) {
    if ((rls[i].es.length() > 1) || (rls[i].ns.length() > 1)) {
      cout << endl
           << "Ошибка в строке " << i + 1
           << ". Ожидаемый или новый символ не может иметь длину более одного "
              "символа! Введите правила корректно!"
           << endl;
      cout << i + 1 << ". " << rls[i].fp << " " << rls[i].es << " " << rls[i].ns
           << " " << rls[i].mv << " " << rls[i].np << endl
           << endl;
      return 1;
    }
  }
  for (i = 0; i < N; i++) {
    if ((rls[i].mv != "l") && (rls[i].mv != "r") && (rls[i].mv != "n")) {
      cout << endl
           << "Ошибка в строке " << i + 1
           << ". Символ передвижения каретки должел принимать значение 'l','r' "
              "или 'n'! Введите правила корректно!"
           << endl;
      cout << i + 1 << ". " << rls[i].fp << " " << rls[i].es << " " << rls[i].ns
           << " " << rls[i].mv << " " << rls[i].np << endl
           << endl;
      return 1;
    } else
      continue;
  }
  return 0;
}