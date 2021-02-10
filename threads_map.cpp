

/***
**  测试map多线程的使用
**  一个put 一个get 一个release
** ##多线程单独读容器是安全的，但是读写共存的时候，要慎重，加锁保护，容易忽视的地方：front empty   (能够注意到的put_back,erase)
****/

#include<iostream>
#include<map>
#include<thread>
#include<vector>


using namespace std;
map<int, int> m_map;


void thread1(string data)
{
    for (int i = 0;i < 1000;i++)
    {
        
        //m_map.insert(make_pair(i, i));
        //printf("thread1[%d,%d]\n", i, i);
    }

}

void thread2(string data)
{
    if (!m_map.empty())
    {

        int second_tmp = 0;
        for (int i = 0;i < 1000;i++)
        {
            std::map<int, int>::iterator it = m_map.find(i);
            if (it != m_map.end())
            {
                if (it != m_map.end())
                {
                    second_tmp = it->second;
                    it->second = 2;
                    printf("thread2[%d,%d]\n", i, it->second);
                }
            }

            


            //second 操作
        }
    }
}

void thread3(string data)
{
       //不做任何操作
}

int main()
{
    string data = "hello";
    m_map.clear();
    thread threa_a(&thread1, data);
    thread threa_b(&thread2, data);
    //thread threa_c(&thread3, data);
    threa_a.join();
    threa_b.join();
    //threa_c.join();


    system("pause");
    return 0;
}
