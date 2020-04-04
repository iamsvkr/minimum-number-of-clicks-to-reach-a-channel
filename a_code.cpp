#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	int limit[2];
	cin >> limit[0] >> limit[1];
	int n;
	int hash[limit[1]+5]={0};
	cin >> n;
	int blocked[n];
	for(int i=0; i<n; i++){
		cin >> blocked[i];
		hash[blocked[i]]++;
	}
	int m;
	cin >> m;
	int input[m],bc[m];
	bc[0]=100000;
	for(int i=0; i<m; i++) {
		cin >> input[i];
		if(i>0){
			bc[i]=input[i-1];
		}
	}
	int xx = input[0],cc=0;
	while(xx){
		cc++;xx/=10;
	}
	int tap=cc;
	for(int i=1; i<m; i++){
		int f=0,a=min(input[i],input[i-1]), b = max(input[i],input[i-1]);
		for(int i=a+1; i<=b; i++){
			if(hash[i]!=1) f++;
		}
		int kk=0;
		for(int i=b+1; i<=limit[1];i++){
			if(hash[i]!=1) kk++;
		}
		for(int i=limit[0]; i<=a; i++){
			if(hash[i]!=1) kk++;
		}
		f=min(f,kk);
		int s=input[i],c=0;
		while(s){
			c++;s/=10;
		}
		int t = 0,mn=INT_MAX,u=i-1,r;
		while(u>0){
			t++;
			r = t+abs(bc[u]-input[i]);
			mn = min(mn, abs(r));
			u--;
		}
		
		tap+=(min(f,min(c,mn)));	
	}
	cout << endl;
	cout << tap;
}	
