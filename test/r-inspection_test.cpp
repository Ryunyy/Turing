#include "incl_test.h"
bool r_insp(vector<struct st> &rls, int N) {
  int i = 0;
  int j = 0;
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
TEST_CASE() {
  std::vector<st> rls;
  rls.resize(1);
  rls[0].fp = "q2";
  rls[0].es = "12";
  rls[0].ns = "21";
  rls[0].mv = "sm";
  rls[0].np = "q3";

  // for "q1"
  REQUIRE(r_insp(rls, 1) == true);
  rls[0].fp = "q1";
  // for "halt"
  REQUIRE(r_insp(rls, 1) == true);
  rls[0].np = "halt";
  // for length
  REQUIRE(r_insp(rls, 1) == true);
  rls[0].es = "1";
  REQUIRE(r_insp(rls, 1) == true);
  rls[0].ns = "2";
  // for move
  REQUIRE(r_insp(rls, 1) == true);
  rls[0].mv = "r";
  // all done
  REQUIRE(r_insp(rls, 1) == false);
}
