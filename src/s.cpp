#include "incl.h"
// extern int chs(string str);

string s(string &str) {
  setlocale(LC_ALL, "RUS");
  // m:
  cout << endl << "Введите вашу строку:    ";
  cin >> str;
  /*Проверка строки
  if(chs(str))*/
  return str;
  /*else {
    cout << "Пожалуйста, введите строку корректно!" << endl;
    goto m;
  }
  */
}
