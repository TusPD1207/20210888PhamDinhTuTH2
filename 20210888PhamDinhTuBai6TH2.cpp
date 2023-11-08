/*
Bài tập 2.6. Giả thuyết Collatz: bắt đầu từ số dương n bất kỳ, nếu n chẵn thì 
chia 2, nếu lẻ thì nhân 3 cộng 1, giả thuyết cho rằng ta luôn đi đến  n = 1. 
Hãy viết chương trình mô phỏng lại quá trình biến đổi để kiếm chứng giả thuyết với giá trị của n nhập từ bàn 
phím.
*/
#include <stdio.h>

void print(int n) {
    printf("n=%d\n", n);
}
int mul3plus1(int n) {
    return n * 3 + 1; //truong hop n la so le
}
int div2(int n) {
    return n / 2;//truong hop n la so chan
}
// khai báo các tham số cho các con trỏ hàm odd, even và output
void simulate(int n, int(*odd)(int), int(*even)(int), void(*output)(int)
/*****************#YOUR CODE HERE - PHAM DINH TU 20210888#*****************/)  {
    (*output)(n);
    if (n == 1) return;
    if (n % 2 == 0) {
        n = (*even)(n);//n la so chan
    } else {
        n = (*odd)(n); //n la la so le
    }
    simulate(n, odd, even, output); //in ra ket qua ham stimulate
}

int main() {
    int (*odd)(int) = NULL;
    int (*even)(int) = NULL;

    /*****************
    # YOUR CODE HERE - Pham Dinh Tu 20210888#
    *****************/
    odd=mul3plus1;
    even=div2; //2 truong hop cua n
    int n;
    scanf("%d", &n);//nhap vao n
    simulate(n, odd, even, print);//in ra cac ket qua
    return 0;
}
