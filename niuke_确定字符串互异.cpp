class Different {
public:
    bool checkDifferent(string iniString) {
        // write code here
        
        #if 0
        int result[256];
        for(size_t i = 0;i < iniString.length();i++)
        {
            result[iniString[i]]++;
        }
        
        for(int i = 0;i < 256;i++)
        {
            if(result[i] > 1)
            {
                return false;
            }
        }
        
        return true;
        
        //上述的用例没过
        #endif
        
        //for 循环 并考虑为空的情况
        if (iniString.empty())
        {
            return true;
        }
        
        for(int i = 0;i<iniString.size();i++)
        {
            for(int j = i + 1;j<iniString.size();j++)
            {
                if(iniString[i] == iniString[j])
                {
                    return false;
                }
            }
        }
        
        return true;
        
    }
};
