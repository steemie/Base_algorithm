class Reverse {
public:
    string reverseString(string iniString) {
        // write code here
        auto len = iniString.size();
        //原理字符串前后进行对应位置的交换
        char tmpstr;
        
        for(decltype(len) i = 0;i != len/2;i++)
        {
            tmpstr = iniString[i];
            iniString[i] = iniString[len - i - 1];
            iniString[len - i- 1] = tmpstr;
        }
        return iniString;
    }
};
