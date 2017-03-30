#include "iostream"
#include "algorithm"
#define MAX 1000

using namespace std;

int main(){

	int a[MAX];
	int T;
	
	cin >> T;
	while (T--){
		int N, P, W, H;    //总共N段，不超过P页，WH长宽，T组数据
		
		cin >> N >> P >> W >> H;
		
		for (int i = 0; i < N; i++){
			cin >> a[i];
		}

		int ans = min(H, W);
		int perline, allline, perpg,lineper,page;  //perpg每页行数，perline 每段行数，lineper每行字数

		for (int i = ans; ans >= 1; i--)
		{
			allline = 0;
			lineper = W / i;			//每行字数
			for (int j = 0; j < N; j++){
				perline = a[j] / lineper;
				if (a[j] % lineper!=0)
					perline ++;
				allline += perline;
			}
			perpg = H / i;		//perpg每页行数

			page = allline / perpg;		//当前字体大小时需要的页数

			if (allline % perpg != 0)
				page++;

			if (page <= P){
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}
