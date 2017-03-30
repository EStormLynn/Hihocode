#include "iostream"
#include "algorithm"
#define MAX 1000

using namespace std;

int main(){

	int a[MAX];
	int T;
	
	cin >> T;
	while (T--){
		int N, P, W, H;    //�ܹ�N�Σ�������Pҳ��WH����T������
		
		cin >> N >> P >> W >> H;
		
		for (int i = 0; i < N; i++){
			cin >> a[i];
		}

		int ans = min(H, W);
		int perline, allline, perpg,lineper,page;  //perpgÿҳ������perline ÿ��������lineperÿ������

		for (int i = ans; ans >= 1; i--)
		{
			allline = 0;
			lineper = W / i;			//ÿ������
			for (int j = 0; j < N; j++){
				perline = a[j] / lineper;
				if (a[j] % lineper!=0)
					perline ++;
				allline += perline;
			}
			perpg = H / i;		//perpgÿҳ����

			page = allline / perpg;		//��ǰ�����Сʱ��Ҫ��ҳ��

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
