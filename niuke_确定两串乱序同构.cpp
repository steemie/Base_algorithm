class Same {
public:
    bool checkSam(string stringA, string stringB) {
        // write code here
        
        #if 0
        //初步想法，第一个的str 分开放入vector中，第二个的去vector遍历。
        vector<string> vectStr,vectStr2;
        string strTmp = "";
        int blank1 = 0,blank2 = 0;
        for(int i =0;i < stringA.size();i++)
        {
            if(stringA[i] != ' ')
            {
                strTmp += stringA[i];
            }
            else
            {
                vectStr.push_back(strTmp);
                strTmp = "";
                blank1++;
            }
            
        }
        
        string strTmp2 = "";
        for(int i =0;i < stringA.size();i++)
        {
            if(stringB[i] != ' ')
            {
                strTmp2 += stringB[i];
            }
            else
            {
                vectStr2.push_back(strTmp2);
                strTmp2 = "";
                blank2++;
            }
            
        }
        
        if(blank1 != blank2 || vectStr.size() != vectStr2.size())
        {
            return false;
        }
        
        
        
        for(int i = 0;i<vectStr.size();i++)
        {
            int flag = 0;
            for(int j = 0;j < vectStr2.size();j++)
            {
                if (vectStr[i] == vectStr2[j])
                {
                    flag = 1;
                    break;
                }
                
                if(j ==  vectStr2.size() - 1 && flag == 0)
                {
                    return false;
                }
            }
        }
        
        return true;
        //通过率0
        #endif
        
        //换一种思路 两个能打乱顺序，
        //那么所含的字符个数和每个字符出现的次数一定是相等的
        //利用hash的方法
        if (stringA.empty() || stringB.empty())
        {
            //都为空呢？
            return false;
        }
        
        if (stringA.size() != stringB.size())
        {
            return false;
        }
        
        int hashtableA[256] = {0};
        int hashtableB[256] = {0};
        
        for(int i = 0;i < stringA.size();i++)
        {
            hashtableA[stringA[i]]++;
        }
        
        for(int i = 0;i < stringB.size();i++)
        {
            hashtableB[stringB[i]]++;
        }
        
        for(int i = 0;i < 256;i++)
        {
            if(hashtableA[i] != hashtableB[i])
            {
                return false;
            }
        }
        return true;
        
        
        
    
    }
};
