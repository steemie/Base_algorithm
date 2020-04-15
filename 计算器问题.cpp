//#include<iostream>
//#include<system.h>
#include<stdlib.h>
#include<stdio.h>
//#include<vector>
//#include<string>
//#include<stack>
//#include<queue>

#include <algorithm>　　　  //通用算法
#include <bitset>　　　　　 //位集容器
#include <cctype>
#include <cerrno>
#include <clocale>
#include <cmath>
#include <complex>　　　　 //复数类
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>　　　　　 //双端队列容器
#include <exception>　　　 //异常处理类
#include <fstream>
#include <functional>　　　 //定义运算函数（代替运算符）
#include <limits>
#include <list>　　　　　　 //线性列表容器
#include <map>　　　　　　 //映射容器
#include <iomanip>
#include <ios>　　　　　　//基本输入／输出支持
#include <iosfwd>　　　　//输入／输出系统使用的前置声明
#include <iostream>
#include <istream>　　　　 //基本输入流
#include <ostream>　　　　 //基本输出流
#include <queue>　　　　　 // 队列容器
#include <set>　　　　　　 //集合容器
#include <sstream>　　　　 //基于字符串的流
#include <stack>　　　　　 //堆栈容器　　　　
#include <stdexcept>　　　 //标准异常类
#include <streambuf>　　　//底层输入／输出支持
#include <string>　　　　　//字符串类
#include <utility>　　　　 //通用模板类
#include <vector>　　　　 //动态数组容器
#include <cwchar>
#include <cwctype>

using namespace std;
//注意小数
// 头文件太多，请忽略

int main()
{

		//+ - * /

		//解析进来的数据
		float a1,a2;
		char b;
		float result = 0;
		while(cin>>a1>>b>>a2)
		{


		if (b == '+')
		{
			result = a1 + a2;
		}
		else if(b == '-')
		{
			result = a1 - a2;
		}
		else if(b == '*')
		{
			result = a1 * a2;
		}
		else if(b == '/')
		{
			if (a2 == 0)
			{
				return 0;
			}
			result = a1 / a2;
		}
		else
		{
			return 0;
		}


		cout<<result<<endl;
	}
	//return result;

	//printf("a\n");
	system("pause");

	return 0;
}
