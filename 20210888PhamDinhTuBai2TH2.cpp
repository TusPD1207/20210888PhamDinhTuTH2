/*
Bài tập 2.2. Viết hàm hoán vị vòng tròn 3 biến a, b, c. 
Sau khi thực hiện hàm, các biến a, b, c tương ứng nhận các giá trị mới b, c, a.
*/
#include <stdio.h>

void rotate(int &x, int &y, int &z) {
    /*****************
    # YOUR CODE HERE - PHAM DINH TU 20210888 #
    *****************/
    int t = x; //gan bien moi t nhan gia tri cua x
    x = y; //gan y vao x
    y = z;//gan z vao y
    z = t;//gan x vao z thong qua t
}
int main() {
    int x, y, z;
    //# Nhập 3 số nguyên
    /*****************
    # YOUR CODE HERE - PHAM DINH TU 20210888 #
    *****************/
    scanf("%d%d%d",&x,&y,&z);
    printf("Before: %d, %d, %d\n", x, y, z);//in ra gia tri ban dau
    rotate(x, y, z);
    printf("After: %d, %d, %d\n", x, y, z);//in ra gia tri sau khi hoan vi
    return 0;
}
