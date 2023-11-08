/*
Bài tập 2.5. Viết các toán tử tính tổng, hiệu, tích và thương của hai số phức
*/
#include <iostream>
#include <ostream>
#include <math.h>
#include <iomanip> 
using namespace std;
struct Complex {
    double real;
    double imag;
};
Complex operator + (Complex a, Complex b) {
    /*****************
    # YOUR CODE HERE - PHAM DINH TU 20210888 #
    *****************/
    return Complex{a.real+b.real,a.imag+b.imag};//cong hai so phuc
}
Complex operator - (Complex a, Complex b) {
    /*****************
    # YOUR CODE HERE - PHAM DINH TU 20210888 #
    *****************/
    return Complex{a.real-b.real,a.imag-b.imag};//tru hai so phuc
}
Complex operator * (Complex a, Complex b) {
    /*****************
    # YOUR CODE HERE - PHAM DINH TU 20210888 #
    *****************/
    return Complex{a.real*b.real-a.imag*b.imag,a.imag*b.real+b.imag*a.real};
    //nhan hai so phuc
}
Complex operator / (Complex a, Complex b) {
    /*****************
    # YOUR CODE HERE - PHAM DINH TU 20210888    #
    *****************/
    double len = b.real*b.real+b.imag*b.imag;//nhan them luong lien hop ra len
    return Complex{(a.real*b.real+a.imag*b.imag)/len,(a.imag*b.real-a.real*b.imag)/len};
    //chia hai so phuc
}
ostream& operator << (ostream& out, const Complex &a) {

out << '(' << std::setprecision(2) << a.real << (a.imag >= 0 ? '+' : '-') << std::setprecision(2) << fabs(a.imag) << 'i' << ')';
    return out; //cai dat do chinh xac cua phep tinh
}
int main() {
    double real_a, real_b, img_a, img_b;
    cin >> real_a >> img_a;
    cin >> real_b >> img_b;//nhap hai so phuc
    Complex a{real_a, img_a};
    Complex b{real_b, img_b};
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;// in ket qua cac phep tinh
    return 0;}
