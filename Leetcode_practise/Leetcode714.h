#pragma once
#include<vector>
#include<algorithm>

using namespace std;

class Leetcode714 {
public:
    int maxProfit_DP(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i-1][0],dp[i-1][1] + prices[i] - fee); //������������� 1.����Ҳ������  2.������У���������
            dp[i][1] = max(dp[i-1][1],dp[i-1][0] - prices[i]); //����������� 1.����Ҳ���� 2.���첻���У���������
        }
        return dp[n - 1][0];
    }

public:
    int maxProfit_Greedy(vector<int>& prices, int fee) {
        int buy = prices[0] + fee;
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] + fee < buy) {
                buy = prices[i] + fee;
            }
            if (prices[i] > buy) {
                profit += prices[i] - buy;
                buy = prices[i];
            }
        }
        return profit;
    }
};