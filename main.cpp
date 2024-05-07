#include<iostream>
#include<vector>

using namespace std;


//dp数组表示爬楼梯方法数量，dp[i]表示i层楼梯有几种走法
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp;
        dp.resize(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
//状态压缩
class Solution {
public:
    int climbStairs(int n) {
        if (n <=2) return n;
        int n_2 = 1;
        int n_1 = 2;
        int res = n;
        
        for (int i = 3; i <= n; i++)
        {
            res = n_1 + n_2;
            n_2 = n_1;
            n_1 = res;
        }
        return res;
    }
};

int main()
{
    Solution s;
    int nums = s.climbStairs(5);
    cout << nums << endl;
}