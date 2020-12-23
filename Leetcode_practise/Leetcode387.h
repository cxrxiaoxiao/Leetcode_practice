#pragma once
#include<string>
#include<unordered_map>
using namespace std;

class Leetcode387 {
public:
    int firstUniqChar(string s) {
        int i = 0;
        int j = 0;
        int k = 0;
        unordered_map<char, int> m;
        while (i < s.size()) {
            m[s[i]]++;
            i++;
        }
        while (j < s.size()) {
            if (m[s[j]] == 1) {
                k = 1;
                break;
            }
            j++;
        }
        if (k == 1) {
            return j;
        }
        else
        {
            return -1;
        }
        
    }
};