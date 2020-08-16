#include "incl.h"

void pointer(int point, string str) {
   for(unsigned int i = 0; i < str.length(); i++) {
       if(i == (unsigned)point) {
           cout << "[" << str[point] << "]";
           i++;
       }
       cout << str[i];
       
   }
   cout << endl;
}
