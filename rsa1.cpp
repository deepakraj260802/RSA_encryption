#include<bits/stdc++.h>
using namespace std;
#define int long long
int fast_expo(int a,int b,int m){
	int res = 1LL;
	while(b>0){
		if(b&1){
			res *= a;
			res %= m;		
		}
		a *= a;
		a %= m;
		b /= 2;
	}
	return res%m;
}
int extendedgcd(int a,int b,int s1,int s2,int t1,int t2){
	if(b==0) return t1;
	if(b>a) return extendedgcd(b,a,s1,s2,t1,t2);
	int q = a/b;
	int r = a%b;
	int s = s1-s2*q;
	int t = t1-t2*q;
	return extendedgcd(b,r,s2,s,t2,t);
}
bool isprime(int a){
	for(int i=2;i*i <= a ;i++){
		if( a%i == 0 ) return false;
	}
	return true;
}
int gen_prime(int l,int h){
	int ans = l + (rand()%((h-l)+1));
	while(!isprime(ans)) ans = (l + (rand()%((h-l)+1)));
	return ans;
}
vector<int> key_gen(int p,int q){
	int n = p*q;	
	int phin = (p-1)*(q-1);
	int e = gen_prime(1,phin);
	int d = (extendedgcd(e,phin,1,0,0,1)+phin)%phin;
	return {e,n,d};
}

int encrypt(int p,int e,int n){
	return fast_expo(p,e,n);
}

int decrypt(int c,int d,int n){
	return fast_expo(c,d,n);
}

signed main(){
	int p = gen_prime(4000LL,7000LL);
	int q = gen_prime(200LL,400LL);
	char ch;
	cin>>ch;
	int k = 283;
	vector<int> v = key_gen(p,q);
	cout<<"p : "<<p<<endl;
	cout<<"q : "<<q<<endl;
	cout<<"e : "<<v[0]<<endl;	
	cout<<"d : "<<v[2]<<endl;
	cout<<"m : "<<v[1]<<endl<<endl;
	cout<<"Plain text : "<<k<<endl;
	int ec = encrypt(k,v[0],v[1]);
	cout<<"Encrypt : "<<ec<<endl;
	int dc = decrypt(ec,v[2],v[1]);
	cout<<"Decrypt : "<<dc<<endl;
}
