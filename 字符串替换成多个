//原题：请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
//说明，分配大小，从后向前替换
class Solution {
public:
	void replaceSpace(char *str,int length) {

        
        if(str == NULL)
        {
            return;
        }
            //直接换就好
        int orlen = 0;
        int blank=0 ;
        int tmplength = length;
        string tmp;
        for(int i = 0;str[i] != '\0';i++)
        {
            orlen++;
            if(str[i] == ' ')
            {
                blank++;
            }
            
        }
        
        int len = orlen + 2*blank;
        if((len + 1) > length)
        {
            return;
        }
        
        //copy
        char *str1 = str + orlen; // 赋值结束符 \0
        char *str2 = str + len;
        while(str1 < str2)
        {
            //特别注意，一定是从后面向前面拷贝赋值
            if(*str1 == ' ')
            {
                *str2-- = '0';
                
                *str2-- = '2';
                
                *str2-- = '%';
                
            }
            else
            {
                *str2-- = *str1;
            }
            
            str1--;
            
        }

	}
};
