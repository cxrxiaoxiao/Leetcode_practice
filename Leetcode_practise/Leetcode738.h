#pragma once
#include<iostream>
#include<string>
using namespace std;
class Leetcode738
{
public:
	int monotoneIncreasingDigits(int N) {
		string strN = to_string(N);
		int i = 1;
		while (i < strN.length() && strN[i - 1] <= strN[i]) {
			i = i + 1;
		}
		if (i == strN.length()) {
			return N;
		}

		while (i > 0 && strN[i - 1] > strN[i]) {
			strN[i - 1] = strN[i - 1] - 1;
			i = i - 1;
		}

		for (int j = i + 1; j < strN.length(); j++) {
			strN[j] = '9';
		}

		return atoi(strN.c_str());
	}
};

