//比较1T 100M  1G的大小，按照从小到大的顺序输出
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
struct nod
{
  int a;
  string b;
};

bool cmp(node a,node b)
{
  return a.a < b.a;
}

int main()
{
  
  nod nod1;
  vector<nod> v1;
  int n;
  cin>>n;
  while(n--)
  {
    string tmp,tmp2;
    int tmp1;
    cin>>tmp;
    if(tmp[tmp.length() - 1] == 'M')
    {
      tmp2 = tmp.sunstr(0,'M');
      stringstream ss;
      
      ss<<tmp2;
      ss>>tmp1;
      nod nodTmp;
      nodTmp.a = tmp1;
      nodTmp.b = tmp;
      v1.push_back(nodTmp);
      
    }
    else if(tmp[tmp.length() - 1] == 'T')
    {
      tmp2 = tmp.sunstr(0,'M');
      stringstream ss;
      
      ss<<tmp2;
      ss>>tmp1;
      nod nodTmp;
      nodTmp.a = tmp1*1000;
      nodTmp.b = tmp;
      v1.push_back(nodTmp);
      
    }
    else if(tmp[tmp.length() - 1] == 'G')
    {
      tmp2 = tmp.sunstr(0,'M');
      stringstream ss;
      
      ss<<tmp2;
      ss>>tmp1;
      nod nodTmp;
      nodTmp.a = tmp1*1000*1000;
      nodTmp.b = tmp;
      v1.push_back(nodTmp);
      
    }
    else
    {
         cout<<"error"<<endl;
      
    }
  }
  
  //排序
  sort(v1.begin(),v1.end(),cmp);
  
  for(int i = 0;i < v1.size();i++)
  {
    cout<<v1[i].b<<endl;
  }
  system("pause");
  return 0;
}
