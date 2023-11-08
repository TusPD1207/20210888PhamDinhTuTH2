/*
Bài tập 2.1.  Viết hàm tính độ dài cạnh huyền của tam giác theo độ hai cạnh góc vuông.
*/
#include <stdio.h>
#include <math.h>
float get_hypotenuse(float x, float y) {
    /*****************
    # YOUR CODE HERE - PHAM DINH TU 20210888 #
    *****************/
    return sqrt(x*x+y*y); //In ra do dai canh huyen theo dinh ly Pytago
}
int main(){
    float x, y;
    scanf("%f%f", &x, &y); 
    float z = get_hypotenuse(x, y); //gan z la canh huyen 
    printf("z = %.2f\n", z); //in ra z chinh xac den hai chu so thap phan
    return 0;
}
