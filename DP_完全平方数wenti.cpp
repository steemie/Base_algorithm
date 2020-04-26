class Solution {
public:
    int numSquares(int n) {

        //这个dp的核心原来还是在于这个数N的分解：3{2,1}  4{3,2,1}
        vector<int> result(n+1,0x7FFFFFFF);
        result[0] = 0;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;i-j*j >=0 ;j++)
            {
                result[i] = min(result[i],result[i-j*j] + 1);
            }

        }

        return result[n];


    }
};
