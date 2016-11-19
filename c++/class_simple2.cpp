#include <iostream>
using namespace std;


class Class {
public:
    Class(void) {
      this -> value = -1;
    }
    void setVal(int value) {
      Class::value = value;
    }
    int getVal(void);
private:
    int value;
};

int Class::getVal(void) {
      return value;
}


int main(void) {
  Class object;
  cout << object.getVal() << endl;
  object.setVal(10);
  cout << object.getVal() << endl;
  return 0;
}

