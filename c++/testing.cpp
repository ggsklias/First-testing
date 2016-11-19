#include <iostream>
using namespace std;

int main()
{
//  int *val = new int;
//  cout << sizeof(val) << endl;
//  cout << sizeof(int) << endl;
//  *val = sizeof(val)/sizeof(int);
//  cout << *val << endl;
//  int *tab = new int[*val];
//  tab[0] = *val;
//  delete val;
//  cout << *tab << endl;
//  delete [] tab;
//  return 0;
  float f[2];
  float *p1 = f, *p2 = p1 + 1;
  int a,b;
  a = p2-p1;
  cout << a << endl;
  b = sizeof(float);
  cout << b << endl;
  cout << a/b;
//  cout << (p2-p1)/sizeof(float);
}

//int main()
//{
//  int tab[5] = {1,2,4,8,16};
//  int *p1 = tab, *p2 = tab +4;
//  for(int *p = p1 + 1; p < p2; p++)
//     *p = p[-1] * 2;
//  cout << tab[1] << tab[2];
//  return 0;
//}
 // float x = 3.14, *p = &x;
 // p[0] = ++x;
 // cout << x;
