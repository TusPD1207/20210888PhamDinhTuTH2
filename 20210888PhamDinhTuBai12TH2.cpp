/* 												     
Bài tập 2.12. Hôm nay, cô giáo giao cho An một câu hỏi hóc búa. Cô cho một danh sách với mỗi phần tử có dạng 
<key, value> và yêu cầu An sắp xếp danh sách đó giảm dần theo giá trị value. Nếu 2 phần tử có value giống nhau 
thì sắp xếp giảm dần theo key. Hãy viết một chương trình sử dụng hàm nặc danh để giúp An làm bài tập.		
*/		    											     
#include<bits/stdc++.h>
using namespace std;
struct element {
    int key;
    int value;
}; //Khai bao truong phan tu
vector<element> lst;
void input(){
    int tmp1, tmp2; //Gan hai bien tmp de cho key va value
    while(cin >> tmp1 && cin >> tmp2){
        element tmp; //Gan bien tmp cho gia tri phan tu
        tmp.key = tmp1;
        tmp.value = tmp2;
        lst.push_back(tmp);//Day phan tu dang xet len danh sach
        //Pham Dinh Tu 20210888
    }
}
void print(){
    for(int i=0; i<lst.size(); i++){
        cout << lst[i].key << " " << lst[i].value << endl;
    }
} //In cac dong key value tu input

int main(){
    input(); //Nhap cac dong key value
    sort(lst.begin(),lst.end(),[] (element a, element b)//Ham sort{
        if(a.value > b.value) return true; //Sap xep cac value
        else if (a.value < b.value) return false;
        else {
            return a.key >= b.key;
        }
    });
    print();//In ra cac dong key value da duoc sap xep
    //Pham Dinh Tu 20210888
}
