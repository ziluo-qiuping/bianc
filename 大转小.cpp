#include<iostream>
#include<string>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
using namespace std;

int isNum(string cc){
	if (cc == "壹"){
		return 1 ;
	} 
	if (cc == "贰"){
		return 1; 
	} 
	if (cc == "叁"){
		return 1; 
	} 
	if (cc == "肆"){
		return 1; 
	} 
	if (cc == "伍"){
		return 1; 
	} 
	if (cc == "陆"){
		return 1; 
	} 
	if (cc == "柒"){
		return 1; 
	} 
	if (cc == "捌"){
		return 1; 
	} 
	if (cc == "玖"){
		return 1; 
	} 
	return 0;
}


string solve(string money, string str,int yi, string wei){
	int tag = 0;
		for ( int i = 0; i <= yi; i+= 2 ){
			//找仟
//			cout << wei << wei << endl;
			if (money.substr(i,2) == "仟"){    
//			cout << wei << wei << "!!!" << endl; 
//				char c = money[i-1];
//				str.append(c);
//				printf("找到了千！！！！\n");
				tag = 1;
//				cout << money.substr(i-2,2) << endl;
				str += money.substr(i-2,2);
				break;
			} 
		}
		if (tag == 0 ){
//				str.append('0');
				str += "零";
				
		}
//		cout << wei << wei<< "bai" << endl;
//		cout << "money"<< money  << endl;
		tag = 0;
		for ( int i = 0; i <= yi; i+= 2 ){
			// 找佰 
//			cout << i << endl;
			if (money.substr(i,2) == "佰"){
				printf("找到了bai！！！！\n");
//				char c = str[i-1];
//				str.append(c);
				tag = 1;
				str += money.substr(i-2,2);
				break;
			} 
			
		}
		
		if (tag == 0){
//				str.append('0');
				str += "零";
			
			}
			
//			cout << wei << wei << endl;
			
		tag = 0	;
//		cout << "str:" << str << wei <<endl;
		for ( int i = 0; i <= yi; i+= 2 ){
			
			// 找什
			if (money.substr(i,2) == "拾"){
//				cout << wei << wei << " !!!!!!!!!!!!!!!!"<< endl;
//				char c = str[i-1];
//				str.append(c); 
//				str += money[i-1];
				tag = 1;
				str += money.substr(i-2,2);
				break;
			} 
		}
		if (tag == 0){
//				str.append('0');
//				str += '0';
				str += "零";
			
		}
		
		tag = 0;	
		for ( int i = 0; i <= yi; i+= 2 ){
			// 找个位
			if (money.substr(i,2) == wei) {
				if ( isNum(money.substr(i-2,2))==1 ){
//					char c = str[i-1];
//				 	str.append(c); 
//					str += money[i-1];
					tag = 1;
					str += money.substr(i-2,2);
//					printf("!!!!!!!!!!!!!") ;
					break;
				} 
			}
		}
		if (tag==0) {
//					str.append('0');
//					str += '0';
					str += "零";
					
				}
	return str;
} 

string ToSamll(string money){
	cout << money << endl;
	
	string str = "";
	int len = money.length();
	printf("长度：%d\n",len);
	
	// 按亿分割 
	int yi = -1;
	for(int i = 0; i < len; i+=2) {
		if (money.substr(i,2) == "亿") {
			yi = i;	
			break;
		}
	}
	printf("亿的下标%d\n",yi);
		
	// 按万分割
	int wan = -1;
	for(int i = 0; i < len; i+=2) {
		if (money.substr(i,2) == "万") {
			wan = i;	
			break;
		}
	}
	
	// 按元分割 
	int  yuan = -1;
	for(int i = 0; i < len; i+=2) {
		if (money.substr(i,2) == "元") {
			yuan = i;	
			break;
		}
	}
		
	printf("分割完了！！！！！！"); 
		
	if (yi != -1) {   //找到了亿 
//		cout << money.substr(0,yi+2) << endl;
		str = solve(money.substr(0,yi+2), str, yi,"亿");	
	}
	
		
	if (wan != -1) {   //找到了万 
		if (yi!=-1){  //且找到了亿 
//			cout << money.substr(yi+2,wan-yi) << endl;
//			cout << str << endl;
			
			str = solve(money.substr(yi+2,wan-yi), str, wan-yi-2,"万");
			
		}
		else { //前面没有亿 
			str += solve(money.substr(0,wan+2), str, wan,"万");	
		}	
	} else {
		str += "零零零零" ;
	}
	
	// 元
	if ( isNum(money.substr(yuan-2,2) )  ){   //各十百千 有 
		if ( wan != -1){ //有万 
			str = solve(money.substr(wan+2,yuan-wan), str, yuan-wan-2,"元");
		}
		if(wan == -1 ){ //没有万 
			if ( yi == -1 ){  // meiyouyi
				str = solve(money.substr(0,yuan+2), str, yuan,"元");
			}
			if ( yi != -1){  // you yi
				
				str = solve(money.substr(yi+2,yuan-yi),str,yuan-yi-2,"元");
			}
		} 
	} else {
			str += "零零零零" ;
	}	
		
	
	 
	cout << "!!!" <<endl;
	// 都没有 
//	if ( yi==-1 && wan == -1 ){
//		
//	}
	
	
	printf("03d\n");
//	printf("%s",str);
//	cout << str << endl;
	return str;
}	

string ToNum(string str ){
//	cout << str << "!!!";
	string num;
	int len = str.length();
	for ( int i = 0; i < len; i+= 2){
		if (str.substr(i,2) == "壹"){
			num += "1";
		}
		if (str.substr(i,2) == "贰"){
			num += "2";
		}
		if (str.substr(i,2) == "叁"){
			num += "3";
		}
		if (str.substr(i,2) == "肆"){
			num += "4";
		}
		if (str.substr(i,2) == "伍"){
			num += "5";
		}
		if (str.substr(i,2) == "陆"){
			num += "6";
		}
		if (str.substr(i,2) == "柒"){
			num += "7";
		}
		if (str.substr(i,2) == "捌"){
			num += "8";
		}
		if (str.substr(i,2) == "玖"){
			num += "9";
		}
			if (str.substr(i,2) == "零"){
			num += "0";
		}
		
	}
	return num;
}

int main(){
//	string a = "你好";
//	cout << a.substr(0,2); 
	
	string str;
	
	str = ToSamll("玖仟零玖拾壹万玖仟零玖拾壹元整");
	cout << "大写：" << str << endl;
	str = ToNum(str);
	cout << "数字：" << str << endl;
	
}


