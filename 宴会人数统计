//想不通为什么只通过了80%的用例
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
struct interval
{
	int a;
	int b;
};

int main()
{

	//需要使用vector把每一次出现的数值记录下来
	//时间 0:24

	int a,b;
	vector<struct interval> v1;
	//vector<int> v2;//用于排序
	while(scanf("%d,%d",&a,&b))
	{
		if(a!=-1 && b!=-1)
		{
			if (a>=12 && a<20 &&b>12 &&b<=20 &&a < b)
			{
				struct interval inter;
				inter.a =a;
				inter.b = b;
				v1.push_back(inter);
				//v2.push_back(a);
				//v2.push_back(b);
			}
			else
			{
				return 0;
			}


		}
		else
		{
			break;
		}
	}

	//计算size，遍历
	//map<int,int> map1;
	int arr[25];

	for(int i = 0;i < 25;i++)
	{
		arr[i] = 0;
	}

	for(int i = 0;i < v1.size();i++)
	{
		struct interval tmp = v1[i];
		int first = tmp.a;
		int last = tmp.b;
		for(int j = first;j<last;j++)
		{
			//map1[j++];
			arr[j] +=1; 
		}
	}

	//sort(v2.begin(),v2.end());


	for(int i = 12;i < 20;i++)
	{
		//if (arr[i]!=0)
		//{
			cout<<"["<<i<<","<<i+1<<")" <<":"<<arr[i]<<endl;
		//}
	}

	//system("pause");
	return 0;
}
