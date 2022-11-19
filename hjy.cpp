#include<iostream>
#include<string>
#include <sstream>
using namespace std;
//用于将输入的string转换成long long int 
long long int my_atoi(string str)
{
	long long int a = 0;
//	char *strData = str;
	stringstream stream(str);  
	stream>>a;  
	return a;
}
string print(long long int n) {
	string s1;
	if (n == 0) s1= "零";
	if (n == 1) s1= "壹";
	if (n == 2) s1= "贰";
	if (n == 3) s1= "叁";
	if (n == 4) s1= "肆";
	if (n == 5) s1= "伍";
	if (n == 6) s1= "陆";
	if (n == 7) s1= "柒";
	if (n == 8) s1= "捌";
	if (n == 9) s1= "玖";
	return s1;
}

