#include <iostream>
//推荐讲解博客地址：<引用>:https://www.cnblogs.com/jay-huaxiao/p/12286133.html
class ListNode
{
public:
    int value;
    ListNode* next;

};


class Solution1 {
public:
    ListNode* ReverseList(ListNode* pHead) {
        
        //我们先定义两个指针，一个pre 一个curr，用来循环切换操作
        ListNode*  pre = NULL;
        ListNode*  curr = pHead;

        //脑海中把那张图想象清楚，断开第一个和第二个节点
        while (curr != NULL)
        {
            //先把原来的保存下来
            ListNode* tempNext = curr->next;
            curr->next = pre;
            pre = curr;     //这一步太精妙了

            curr = tempNext;
        }
        return pre;
        

    }
};
