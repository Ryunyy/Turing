#include "incl.h"

bool r_insp(vector<struct st> &rls, int N) {
  int i = 0;
  int j = 0;

  for (i = 0; i < N; i++) {
    if (rls[i].fp != "q1")
      continue;
    else
      break;
  }
  if (i == N) {
    cout << endl
         << "Нет положения 'q1'! Пожалуйста, введите правила корректно!" << endl
         << endl;
    return 1;
  }

  for (i = 0; i < N; i++) {
    if (rls[i].np != "halt")
      continue;
    else
      break;
  }
  if (i == N) {
    cout << endl
         << "Нет положения 'halt'! Пожалуйста, введите правила "
            "корректно!"
         << endl
         << endl;
    return 1;
  }

  for (i = 0; i < N; i++) {
    if (rls[i].np == "halt") {
      if (i == (N - 1))
        break;
      else
        i++;
    } else {
      for (j = 0; j < N; j++) {
        if (rls[i].np == rls[j].fp)
          break;
        else
          continue;
      }
      if (j == N) {
        cout << endl
             << "Нет положения '" << rls[i].np
             << "'! Пожалуйста, введите правила "
                "корректно!"
             << endl
             << endl;
        return 1;
      }
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

  for (i = 0; i < N - 1; i++) {
    for (j = i + 1; j < N; j++) {
      if (rls[i].fp == rls[j].fp && rls[i].es == rls[j].es) {
        cout << endl
             << "Ошибка в строках " << i + 1 << " и " << j + 1
             << " программа не знает что делать с '" << rls[i].es
             << "' Введите правила корректно!" << endl;
        cout << i + 1 << ". " << rls[i].fp << " " << rls[i].es << " "
             << rls[i].ns << " " << rls[i].mv << " " << rls[i].np << endl
             << endl;
        cout << j + 1 << ". " << rls[j].fp << " " << rls[j].es << " "
             << rls[j].ns << " " << rls[j].mv << " " << rls[j].np << endl
             << endl;
        return 1;
      }
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
