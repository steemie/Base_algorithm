class Replacement {
public:
    string replaceSpace(string iniString, int length) {
        // write code here
        
        //开辟额外的空间
        string str = "";
        for(int i = 0;i<length;i++)
        {
            if(iniString[i] == ' ')
            {
                str +="%20";
            }
            else
            {
                str += iniString[i];
            }
        }
        
        return str;
    }
};
