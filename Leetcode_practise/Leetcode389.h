#pragma once
#include<string>
#include<unordered_map>
using namespace std;

class Leetcode389 {
public:
    char findTheDifference(string s, string t) {
        if (s.empty()) {
            return t[0];
        }
        unordered_map<char, int> m_s;
        unordered_map<char, int> m_t;
        for (int i = 0; i < s.size(); i++) {
            if (m_s.count(s[i])) {
                m_s[s[i]] ++;
            }
            else
            {
                m_s[s[i]] = 1;
            }
        }

        for (int j = 0; j < t.size(); j++) {
            if (m_t.count(t[j])) {
                m_t[t[j]] ++;
            }
            else
            {
                m_t[t[j]] = 1;
            }
        }

        for (int k = 'a'; k <= 'z'; k++) {
            if (m_s[k] != m_t[k]) {
                return k;
            }
        }
        return 0;
    }
};