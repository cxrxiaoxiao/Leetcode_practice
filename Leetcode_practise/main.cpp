#include<iostream>
#include<string>
#include<vector>
#include "Leetcode714.h""

using namespace std;

int main() {
	vector<int> num = {1,3,2,8,4,9};
	int fee = 2;
	Leetcode714 leetcode;
	cout <<leetcode.maxProfit_Greedy(num, fee) << endl;
}
