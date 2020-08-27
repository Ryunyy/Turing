#include "incl.h"
extern bool check_row(string &str);

string s(string &str) {
  setlocale(LC_ALL, "RUS");
  do {
    cout << endl << "Введите вашу строку:    ";
    cin >> str;
  } while (check_row(str));

  return str;
}
