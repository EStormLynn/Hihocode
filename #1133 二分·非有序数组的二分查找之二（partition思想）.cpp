#include <cstdio>
int e[1000010];
int main()
{
	int n,k,i,h,l=1,tl,th,m;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) scanf("%d",e+i);
	h=n;
	while(true){
		tl=l;th=h;m=e[tl];
		while(tl<th){
			while(tl<th&&e[th]>m) th--;
			e[tl]=e[th];
			while(tl<th&&e[tl]<m) tl++;
			e[th]=e[tl];
		}
		if(tl==k) {printf("%d\n",m);break;}
		if(tl<k) l=tl+1;
		else h=tl-1;
	}
	return 0;
}
//partition思想，类似快排