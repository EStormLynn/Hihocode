#include<iostream>
typedef long long LL;
using namespace std;

LL gcd(LL a,LL b){
	if(b==0)
		return a;
	return gcd(b,a%b);
}

LL extend_gcd(LL a, LL b,LL &x,LL &y){
	if(b==0){
		x=1;
		y=0;
		return a; 
	}

	LL ans=extend_gcd(b,a%b,x,y);
	LL temp=x;
	x=y;
	y=temp-(a/b)*y;
	return ans;
	
}

int main(void){
	LL s1,s2,v1,v2,m;
	while(cin>>s1>>s2>>v1>>v2>>m)  
    { 
		LL A,B,C,D,x,y;
		 
		A = v1 - v2;
		B = m;
		C = s2 - s1;
		
		if (A < 0) 
			A = A + m ;
		D = gcd(A, B);
		
		if (C % D) 
			cout<<-1<<endl;
		
		A = A / D;
		B = B / D;
		C = C / D;
		
		x = extend_gcd(A, B,x,y);
		x = (x * C) % B;
		while (x < 0){
			x = x + B;
		} 
		cout<<x<<endl; 
	} 
	return 0; 

} 




