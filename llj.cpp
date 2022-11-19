#include<iostream>
#include"hjy.cpp" 
#include<string> 
using namespace std;
string result="";
/*
print函数负责打印0到9的中文大写.
thousandmaxprint实现不超过一万的数的中文输出.
tenthousandmaxprint实现不超过一亿的数的中文输出.
hundredbillionmaxprint实现不超过一万亿的中文输出.
check判断数字的区间范围 
flag标志是否需要输出“元整” ，flag=0标志为需要，反之不需要 
*/
//string print(long long int n);
void thousandmaxprint(long long int n,int flag);
void tenthousandmaxprint(long long int n,int flag);
void hundredbillionmaxprint(long long int n);

string check(string num){
	long long int n=my_atoi(num); 
	if (n >= 100000000){//大于一亿 
		hundredbillionmaxprint(n);
	}	
	else{
		if (n >= 10000)//大于一万 
			tenthousandmaxprint(n,0);
		else //小于一万 
			thousandmaxprint(n,0);
	}
	return result;
}

void thousandmaxprint(long long int n,int flag) {
	int bit[4] = { 0,0,0,0 };
	bit[0] = n / 1000;//千位 
	bit[1] = n % 1000 / 100;//百位 
	bit[2] = n % 100 / 10;//十位 
	bit[3] = n % 10;//个位 
	int start = 0;
	//开始状态变量,当其为1时才会开始打印
	int firstzero = 1;
	//寻找中间的第一个0,输出后会置为0
	int alwayszero = 1;
	//是否从第一个0开始全部是0

	//如果n=0
	if (n == 0)
		result+=print(n);
	else {
		//开始遍历，tempcount表示从前往后第几位 0=千位，1=百位 
		for (int tempcount = 0; tempcount < 4; tempcount++) {
			if (bit[tempcount] != 0 || tempcount == 3)
				//寻找到最后一位或已经遍历到最后一位
				start = 1;
			if (start) {
				if (bit[tempcount] != 0) {
					if (tempcount == 0) {
						result+=print(bit[tempcount]);
						result+="仟";
					}
					if (tempcount == 1) {
						result+=print(bit[tempcount]);
						result+="佰";
					}
					if (tempcount == 2) {
						result+=print(bit[tempcount]);
						result+="拾";
					}
					if (tempcount == 3) {
						result+=print(bit[tempcount]);
					}
				}
				else {
					if (firstzero && tempcount < 3) {
						//如果是第一个0且不是最末位,则判断是否之后全是0.
						for (int i = tempcount; i < 4; i++)
							if (bit[i] != 0)
								alwayszero = 0;
						if (!alwayszero)
							//如果不是全部是0,则输出一个0且将第一个0状态置为0.
							result+=print(bit[tempcount]);
						firstzero = 0;
					}
				}
			}
		}
	}
	if(flag==0) result+="元整";
}

/*
分离万以上和万以下的部分应用上面定义好的函数.
*/
void tenthousandmaxprint(long long int n,int flag) {
	int n1 = n / 10000;
	int n2 = n % 10000;
	if (n1 != 0) {
		thousandmaxprint(n1,1);
		result+="万";
	}
	if (n2 != 0) {
		if (n2 < 1000) result+="零";
		thousandmaxprint(n2,1);
	}
	if(flag==0) result+="元整";
}
/*
原理基本同上.
*/
void hundredbillionmaxprint(long long int n) {
	int n1 = n / 100000000;
	int n2 = n % 100000000;
	thousandmaxprint(n1,1);
	result+="亿";
	if (n2 != 0)
		tenthousandmaxprint(n2,1);
	result+="元整";
}

