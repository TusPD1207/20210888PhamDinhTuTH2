/*
Bài 2.9. Tính hàm sigmoid
Dưới đây cung cấp đoạn code đơn giản để tính hàm sigmoid theo công thức trực tiếp. Hãy viết hàm tính xấp xỉ sigmoid(x) đến độ chính xác  10−6  và có tốc độ nhanh hơn ít nhất 30% so với code đơn giản.
Gợi ý: sử dụng kỹ thuật "chuẩn bị trước" như trong slide.#include <vector>
*/
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstdio>
#include<iostream>
using namespace std;
const int LIMIT = 100;
const int NUM_ITER = 100000;
const int NUM_INPUTS = NUM_ITER * 100; //khai bao mot so gia tri const

double sigmoid_slow(double x) {
    return 1.0 / (1.0 + exp(-x)); //ham sigmoid cham
}
double x[NUM_INPUTS];
void prepare_input() {
    const int PRECISION = 1000000;
    const double RANGE = LIMIT / 20.0;
    for (int i = 0; i < NUM_INPUTS; ++i) {
        x[i] = RANGE * (rand() % PRECISION - rand() % PRECISION) / PRECISION;
    } //chuan bi dau vao 
}
//# BEGIN fast code
//# khai báo các biến phụ trợ cần thiết
/*****************/
#define MAX_N 100000
#define denta 0.0001
double sigmoid[MAX_N];
const double start = -5.0;
const double stop = 5.0;//Cac gia tri phu tro can thiet
//PHAM DINH TU - 20210888
/*****************/

//# hàm chuẩn bị dữ liệu
void precalc() {
    double foo = start;
    for(int i=0; i<MAX_N; i++){
        sigmoid[i] = sigmoid_slow(foo); 
        foo += denta; //chuan bi du lieu de kiem tra ham sigmoid slow
    }
//PHAM DINH TU - 20210888
}
//# hàm tính sigmoid(x) nhanh sigmoid_fast(x)
inline double sigmoid_fast(double x) {
    /*****************/
    if(x < start) return 0.0;
    if(x > stop) return 1.0;
    int i = floor((x - start) / denta);
    return sigmoid[i] + ((sigmoid[i+1] - sigmoid[i]) * (x - start - i*denta)) / (denta);

    /*****************/ //tra ve gia tri ham sigmoid fast
}

//# END fast code

double benchmark(double (*calc)(double), vector<double> &result) {
    const int NUM_TEST = 20;//so lan test
    double taken = 0;
    result = vector<double>();
    result.reserve(NUM_ITER);
    int input_id = 0;
    clock_t start = clock();
    for (int t = 0; t < NUM_TEST; ++t) {
        double sum = 0;
        for (int i = 0; i < NUM_ITER; ++i) {
            double v = fabs(calc(x[input_id]));
            sum += v;
            if (t == 0) result.push_back(v);
            if ((++input_id) == NUM_INPUTS) input_id = 0;
        }
    }
    clock_t finish = clock();
    taken = (double)(finish - start);
//# printf("Time: %.9f\n", taken / CLOCKS_PER_SEC);
    return taken;
}

bool is_correct(const vector<double> &a, const vector<double> &b) {
    const double EPS = 1e-6;//khai bao bien const
    if (a.size() != b.size()) return false;
    for (unsigned int i = 0; i < a.size(); ++i) {
        if (fabs(a[i] - b[i]) > EPS) {
            return false;
        }
    }
    return true;
}//khai  bao ham kiem tra boolean de so sanh voi ham slow, fast

int main() {
    prepare_input();
    precalc();//nhap du lieu
    vector<double> a, b;
    double slow = benchmark(sigmoid_slow, a);
    double fast = benchmark(sigmoid_fast, b);//tinh ham sigmoid theo hai cach
    double xval;
    scanf("%lf", &xval);//nham vao gia tri xval de tinh ham sigmoid
    printf("%.2f \n", sigmoid_fast(xval));
    if (is_correct(a, b) && (slow/fast < 1.3)) {
        printf("Correct answer! Your code is faster at least 30%%!\n");
    } 
    else {
        printf("Wrong answer or your code is not fast enough!\n");
    }
return 0;
