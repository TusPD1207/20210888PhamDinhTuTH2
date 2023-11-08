/*
Bài tập 2.7. Viết hàm tính tổng các phần tử trong hai mảng. Yêu cầu sử dụng function template để cho phép hàm làm việc với các mảng số nguyên lẫn số thực.
*/
#include <iostream>
using namespace std;

template <class T> T arr_sum( T a[], int m, T b[], int n){
    T c = 0;
    for(int i=0;i<m;i++) c+=a[i];//tinh tong cac phan tu trong mang thu nhat
    for(int i=0;i<n;i++) c+=b[i];//tinh tong cac phan tu trong mang thu hai
    return c;
}
//# viết hàm arr_sum
/*****************
# YOUR CODE HERE - PHAM DINH TU 20210888 #
*****************/

int main() {
    int val;
    cin >> val;
    
    {
        int a[] = {3, 2, 0, val};//gan mot so nguyen val vao mang a
        int b[] = {5, 6, 1, 2, 7};
        cout << arr_sum(a, 4, b, 5) << endl; //tinh tong cac phan tu
    }
    {
        double a[] = {3.0, 2, 0, val * 1.0};//nhan them 1.0 vao val thanh double
        double b[] = {5, 6.1, 1, 2.3, 7};
        cout << arr_sum(a, 4, b, 5) << endl;//tinh tong cac phan tu
    }

    return 0;
}
