
class Zipper {
public:
    string zipString(string iniString) {
        // write code here
        int originalStrSize = iniString.size();
        char strTmp = iniString[0];
        string str = "";
        if( 0 == originalStrSize || 1 == originalStrSize)
        {
            return str;
        }
        
        int tmp = 0;

        //这里的i一定要特别注意从0开始，否则会出错


        for(int i = 0;i < originalStrSize;i++)
        {

            //主要是逻辑的处理
            if (i != originalStrSize - 1 && iniString[i] == strTmp)
            {
                tmp++;
            }
            else if(i == originalStrSize - 1 && iniString[i] == strTmp)
            {
                tmp++;
                str += strTmp;
                str += to_string(tmp);
            }
            else if(i != originalStrSize - 1 && iniString[i] != strTmp)
            {
                
                str += strTmp;
                str += to_string(tmp);
                strTmp = iniString[i];
                tmp = 1;
            }
            else
            {
                str += strTmp;
                str += to_string(tmp);
                str += iniString[i];
                str += '1';
            }
                
            
        }
        
        if (str.size() >= iniString.size())
        {
            return iniString;
        }
        
        return str;
    }
};
