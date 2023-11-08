/* 
Bài tập 2.11. Cho 2 đa thức A(x) và B(x) tương ứng có bậc N và M. Hãy tính ma trận tích C(x) = A(x) * B(x) 
có bậc N+M−1.
*/
#include<bits/stdc++.h>
using namespace std;
typedef complex<double> base;  //Khai bao bac cua da thuc
typedef vector<base> vb;
void input(int &n, int &m, vb &x, vb &y){
    cin >> n; //Nhap bac n cua da thuc
    for(int i=0; i<=n; i++){
        int tmp;
        cin >> tmp;
        base mycomplex(tmp,0);
        x.push_back(mycomplex); //Day gia tri mycomplex cho da thuc 1
    }
    cin >> m;
    for(int i=0; i<=m; i++){
        int tmp;
        cin >> tmp;
        base mycomplex(tmp,0);
        y.push_back(mycomplex); //tuong tu voi da thuc 2
    }
}
void fast_fourier_transform(vb & a, bool revert){ 
//Dung ham bien doi fourier nhanh
	int n = (int)a.size();
	for(int i=1, j=0; i<n; ++i){
		int bit = n >> 1; //Dung bit de danh vi tri
		while(j>=bit){
			j =j- bit;
             bit=bit>>1;
        }
		j =j+ bit;
		if (i < j) swap (a[i], a[j]); //Thay doi vi tri cac so mu 
	}
	for(int len=2; len<=n; len<<=1){ 
		double ang = 2*M_PI/len; //ham xor bang cos va sin
        if(revert==1) ang=-ang;
		complex<double> wlen (cos(ang), sin(ang));
		for (int i=0; i<n; i+=len) {
			complex<double> w (1);
			for (int j=0; j<len/2; ++j) {
				complex<double> u = a[i+j],  v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
				w =w * wlen;
			}
		}
	}
	if(revert==1)
		for(int i=0; i<n; ++i)
			a[i] /=n;
}

int multiply(int n, int m, vb x, vb y){
    int p = 1;
	while(p < max (n, m)) p=p<<1;
	p=p<<1;
	x.resize(p);
    y.resize(p); //Nhan va dinh dang lai tich hai da thuc

	fast_fourier_transform(x, false);
    	fast_fourier_transform (y, false); //Ap dung ham bien doi fourier

    vector<base> h(p);
	for (int i=0; i<p; i++)
		h[i] =x[i]*y[i]; //Nhan cac so mu giong nhau bang ham for

	fast_fourier_transform (h, true); 
//Ap dung ham bien doi fourier voi da thuc con
	int res = (int)(real(h[0])+0.5);
	for (int i=1; i<=p; i++){
		res = res ^ (int)(real(h[i])+0.5); //XOR
	}
    return res;
}
int main(){
    int n, m;
    vector<base> x,y;
    input(n,m,x,y);
    cout << multiply(n,m,x,y);
    //Pham Dinh Tu - 20210888
}
