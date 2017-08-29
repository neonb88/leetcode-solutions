#include <iostream>
#include <cstring>
#include <string>
#include <typeinfo>
using namespace std;


#define ZERO 48
#define NINE 57
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define MAX_DIGITS 10







bool is_tab(int i) {
  return i == 9;
}

bool is_space(int i) {
  return isspace(i) || is_tab(i);
}
  
bool is_digit(int i) {
  return i >= ZERO && i <= NINE;
}
  
bool is_minus(int i) {
  return i == 45;
}

bool is_plus(int i) {
  return i == 43;
}



  int myAtoi(string str) {
    int out = 0;
    
    
    
    
    
    int len = str.length();
    bool inWhiteSpace = true;
    bool read = true;
    bool neg = false;
    bool plus_seen = false;
    
    bool wrapped = false;
    int digits_read = 0;
    bool leading_zeros = true;
    
    for (int i = 0; i < len && read; ++i) {
      int currInt = str[i];
      
      
      if (inWhiteSpace && is_space(currInt)) {
        inWhiteSpace = true;
      } else {
        inWhiteSpace = false;
        
        
        if (is_digit(currInt)) {
          out = (out * 10) + currInt - ZERO;
          if (currInt != ZERO) {
            leading_zeros = false;
          }
          if (!leading_zeros) {
            ++digits_read;
          }
          
          
        } else {
          if (!neg && !plus_seen && is_minus(currInt)) {
            neg = true;
          } else if (!neg && !plus_seen && is_plus(currInt)) {
            plus_seen = true;
          } else {
            read = false;
          }
        } 
      }
      
      if (digits_read > MAX_DIGITS || out < 0) {
        read = false;
        wrapped = true;
      }
   }
    
    if (wrapped) {
      return neg ? INT_MIN : INT_MAX;
    }
    
    if (neg) {
      return -out;
    } else {
      return out;
    }
  }




// To execute C++, please define "int main()"
int main() {
  
  cout << myAtoi("  10522545459");
  
  cout << "\n\n";
  cout << myAtoi("  +004500");
  
  /*
  
  
  
 _________________________________ 
 _________________________________ 
 
 
 
  morals : "0" == 49
  
          backspaces only apply after printing
          atoi(" 8\b") == 8
          atoi(" \b8") == 0
          "\t".length() == 1 
  
          0 == false
          other int == true  
          typeid(str[index]).name() == "c"
          
          ' '  == 32
          '\r' == 13
          '\f' == 12
          '\v' == 11
          '\n' == 10
          '\t' == 9
  _________________________________ 
 _________________________________ 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
//  cout << "  first   8\b";
  string first = " 1 ";
  string backspace = " 1 d\b";
  cout << first.compare(backspace);
  cout << "\n\n";
  
  cout << atoi("    \b 8");
  */
  
  return 0;
  
}
