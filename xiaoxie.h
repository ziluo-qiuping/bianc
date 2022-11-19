#include<iostream>
#include<cstdio>
using namespace std;
bool judge(string input)
{
	int flag=0;
	int i=0;
	while(i<input.size())
	{
		if(!isdigit(input[i])){
		cout<<"ÊäÈë´íÎó";
		return 0;
		}
		i++;
	}
	if(flag==1)return 1;
	
}

