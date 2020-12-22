#pragma once
#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

class Leetcode290
{
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> m;
        int i = 0;
        int count = 0;
        for (int k = 0; k < s.size(); k++) {
            if (s[k] == ' ') {
                count++;
            }
        }
        if (count + 1 != pattern.size()) {
            return false;
        }
        for (int j = 0; j < pattern.size() && i < s.size(); j++) {
            string temp = " ";
            while (i < s.size() && s[i] != ' ') {
                temp += s[i];
                i++;
            }
            if (m.count(pattern[j])) {
                if (m[pattern[j]] != temp) {
                    return false;
                }
            }
            else {
                for (auto a : m) {
                    if (a.second == temp) {
                        return false;
                    }
                }
            }
            m[pattern[j]] = temp;
            i++;
        }
        return true;
    }
};

