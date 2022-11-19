#include "UI.h"
using namespace std;
void OutputUI(string o_str)
{
    string str_1 = "****************土木工程爆破队牌数值转换器?***********************";
    string str_2 = "***********     转换后的数值为：";
    cout<<str_1<<endl<<str_2<<o_str<<endl;
    
};
void AskUI()
{
    string str_1 = "****************土木工程爆破队牌数值转换器?***********************";
    string str_2 = "***                                                            ***";
    string str_3 = "***        欢迎使用土木工程爆破队牌数值转换器(?˙▽˙?)        ***";
    string str_4 = "***                                                            ***";
    string str_5 = "***  功能列表 ? ?)?*??:                                        ***";
    string str_6 = "***                                                            ***";
    string str_7 = "***    1、输入y进行下一次数值转换                              ***";
    string str_8 = "***                                                            ***";
    string str_9 = "***    2、输入\"!\" 退出程序                                     ***";
    string str_10 ="***                                                            ***";
    string str_11 ="***                                                            ***";
    string str_12 ="******************************************************************";
    cout<<str_1<<endl<<str_2<<endl<<str_3<<endl<<str_4<<endl<<str_5<<endl;
	cout<<str_6<<endl<<str_7<<endl<<str_8<<endl<<str_9<<endl<<str_10<<endl<<str_11<<endl<<str_12<<endl;
};
void ErrorUI()
{
    string str_1 = "****************土木工程爆破队牌数值转换器?***********************";
    string str_2 = "***             检测到您的输入似乎不合法(⊙o⊙)                ***";
    string str_3 = "***                                                            ***";
    string str_4 = "***  功能列表  ? ?)?*??：                                      ***";
    string str_5 = "***                                                            ***";
    string str_6 = "***    1、按\"n\"重新进行输入                                    ***";
    string str_7 = "***                                                            ***";
    string str_8 = "***    2、按\"!\" 退出程序                                       ***";
    string str_9 = "******************************************************************";
    cout<<str_1<<endl<<str_2<<endl<<str_3<<endl<<str_4<<endl<<str_5<<endl;
	cout<<str_6<<endl<<str_7<<endl<<str_8<<endl<<str_9<<endl;
};
