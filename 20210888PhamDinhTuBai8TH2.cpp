/*
Bài 2.8. Viết hàm so sánh cho thuật toán sắp xếp. 
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    int val1, val2;
    cin >> val1 >> val2;//them val1, val2 vao cac day so, gia tri -10 va -5
    vector< vector<int> > a = {
        {1, 3, 7},
        {2, 3, 4, val1},
        {9, 8, 15},
        {10, val2},//in ra cac day so
    };
    //# sắp xếp các vector trong a theo tổng các phần tử giảm dần
    /*****************
    # YOUR CODE HERE - PHAM DINH TU 20210888#
    *****************/
    sort(a.begin(), a.end(), [](const vector<int>&p, const vector<int>&q){
        return accumulate(p.begin(),p.end(),0)>accumulate(q.begin(),q.end(),0);
    }); //sap xep cac day so theo thu tu
    for (const auto &v : a) {
        for (int it : v) {
            cout << it << ' ';
        }
        cout << endl;//dung ham for de sap xep
    }
    return 0;
}