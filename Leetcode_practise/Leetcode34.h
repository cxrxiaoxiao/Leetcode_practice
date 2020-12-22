#pragma once
#include<vector>
#include<iostream>
using namespace std;

class Leetcode34
{
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int>::iterator it;
		int count = 0; 
		int k = 0;
		int begin = -1; 
		int end = -1;
		for (it = nums.begin(); it != nums.end(); it++) {
			if (*it == target && k != 1) {
				begin = count;
				k = 1;
			}
			if (*it != target && k == 1) {
				end = count-1;
				k = 0;
			}
			count++;
		}
		if (k == 1) {
			end = nums.size() - 1;
		}
		return {begin,end};
	}  //≥£πÊO£®n£©
};

