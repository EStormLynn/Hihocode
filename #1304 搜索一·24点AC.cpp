#include<iostream>

using namespace std;

double number[4]; 
double nowNumber[4];
char ops[3];
char opType[4] = { '+', '-', '*', '/' };
bool used[4]={false};
int num;

double calc(double a, double b, char c){
	double s = 0.0;
	switch (c)
	{
		case '+':		s = a + b;break;
		case '-':		s = a - b;break;
		case '*':		s = a*b;break;
		case '/':		if (b != 0) s = b / a;break;
		default:		break;
	}
	return s;
}

bool makeOperation(int depth){
	if(depth>=3){
		if (      calc(calc(number[0], number[1],ops[0]), calc(number[2], number[3],ops[1]),ops[2]) == 24      //(A#B)#(C#D) 
			||       calc(calc(calc(number[0],number[1],ops[0]),number[2],ops[1]),number[3],ops[2]) == 24	   //((A#B)#C)#D
			|| calc(number[0], calc(number[1], calc(number[2], number[3], ops[2]), ops[1]), ops[0]) == 24	   //A#(B#(C#D))
			|| calc(calc(number[0], calc(number[1], number[2], ops[1]), ops[0]), number[3], ops[2]) == 24	  //(A#(B#C))#D 
			|| calc(number[0], calc(calc(number[1], number[2], ops[1]), number[3], ops[2]), ops[0]) == 24     //A#((B#C)#D)
			)          
			
			return true;
		else
			return false;
	} 

	for(int i=0;i<4;i++){
		ops[depth] = opType[i];
		if (makeOperation(depth + 1))
			return true;
	}
	return false;
}
	
bool makeNumber(int depth){
	if(depth>=4)
		return makeOperation(0);
	
	for(int i=0;i<4;i++){
		if(!used[i]){
			nowNumber[depth]=number[i];
			used[i]=false;
			
			if(makeNumber(depth+1))
				return true;
				
			used[i]=false;			
		}		
	}
	return false;
}

int main(){
	int n;
	cin>>n;
	
	while(n--){
		for (int i = 0; i < 4; i++)
			cin >> number[i];

		if (makeNumber(0))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	} 
	return 0;
}