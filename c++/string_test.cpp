//#include <iostream>
//#include <string>
//
//using namespace std;
//
//void printInfo(string &s) {
//        cout << "length = " << s.length() << endl;
//        cout << "capacity = " << s.capacity() << endl;
//        cout << "max size = " << s.max_size() << endl;
//        cout << "---------" << endl;
//}
//
//int main(void) {
//        string TheString = "content";
//        printInfo(TheString);
//        for(int i = 0; i < 10; i++)
//        {
//          TheString += TheString;
//          printInfo(TheString);
//        }
//        return 0;
//}
//
///////////////////////////////////
#include <iostream>  
#include <string> 

using namespace std; 

int main(void) { 
  string TheString; 
  for(char c = 'A'; c <= 'Z'; c++) 
    TheString.push_back(c); 
  cout << TheString << endl; 
  return 0; 
}
///////////////////////////////////
//#include <iostream> 
//#include <string> 
//
//using namespace std;
//
//int main(void) {
//  string TheString = "CONTENT"; 
//  for(int i = 0; i < TheString.length(); i++)
//    TheString[i] = TheString[i]  - 'C' + 'c';
//  cout << TheString << endl;
//  return 0;
//}
///////////////////////////////////
//
//
//
//#include <iostream> 
//#include <string> 
//
//using namespace std;
//
//void PrintInfo(string &s) {
//  cout << "content =\"" << s << "\" ";
//  cout << "capacity = " << s.capacity() << endl;
//  cout << "max size = " << s.max_size() << endl;
//  cout << "---------" << endl;
//}
//
//int main(void) {
//  string TheString = "content"; 
//  PrintInfo(TheString);
//  TheString.reserve(100);
//  PrintInfo(TheString);
//  TheString.reserve(0);
//  PrintInfo(TheString);
//  return 0;
//}
