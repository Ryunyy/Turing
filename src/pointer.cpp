#include "incl.h"

void pointer(int point, string str) {
   for(unsigned int i = 0; i < str.length(); i++) {
       cout << str[i];
       if(i == (unsigned)point-1) {
           cout << "[" << str[point] << "]";
       }
   }
   cout << endl;
}
