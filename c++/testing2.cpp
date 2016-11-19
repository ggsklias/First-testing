    #include <iostream>
    #include <string>
    using namespace std;

    int main() {
        char t[3][3];
        char *p = (char *)t;
        for(int i = 0; i < 9; i++)
            *p++ = 'a' + i;
        p = (char *)t;
        for(int i = 0; i < 9; i++)
            cout << *p++ << endl;
        cout << t[1][1] << endl;
        return 0;
    }

//
//namespace S1 {
//    int A = 1;
//    }
//
//    namespace S2  {
//    int A = 2 ;
//    }
//
//    int main(void) {
//        {
//          using namespace S1;
//          S2::A = A + 1;
//        }
//        { using namespace S2;
//          S1::A = A + 1;
//        }
//        cout << S1::A << S2::A;
//        return 0;
//    }
//

//int main() {
//    short s = 1;
//    int i = 2;
//    long l = 3;
//    float f = 4.4;
//    double d = 6.6;
//    cout << s/f << endl;
//    cout << f/i << endl;
//    cout << d/s << endl;
//    return 0;
//}
