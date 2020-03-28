//在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
//请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        
        
        //常规访问，没访问一个判断大小
        int size1 = array.size();
        int size2 = array[0].size();
        int j = 0;
        for (int i = size1 - 1,j = 0;i >=0&&j<=size2-1;)
        {
            if (target < array[i][j])
            {
                i--;
                continue;
            }
            else if(target > array[i][j])
            {
                j++;
                continue;
            }
            else
            {
                return true;
            }
            
        }
        
        return false;
    }
};
