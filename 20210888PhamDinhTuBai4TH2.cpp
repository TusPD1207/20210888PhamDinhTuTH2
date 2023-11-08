/*
Bài tập 2.4. Viết các hàm tính lập phương của số nguyên và số thực.
*/
#include <stdio.h>

int cube(int x) {
    //# trả về lập phương của x
    /*****************
    # YOUR CODE HERE - PHAM DINH TU 20210888 #
    *****************/
    return x*x*x;
}
//# viết hàm tính lập phương của một số kiểu double
/*****************
# YOUR CODE HERE - PHAM DINH TU 20210888 #
*****************/
double cube(double x){
    return x*x*x;
}

int main() {
    int n;
    double f;
    scanf("%d %lf", &n, &f);
    printf("Int: %d\n", cube(n));//in ra lap phuong cua so nguyen n
    printf("Double: %.2lf\n", cube(f));//in ra lap phuong cua so thuc f
    return 0;
}
