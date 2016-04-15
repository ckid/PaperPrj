
#ifndef _POLICY
#define _POLICY

#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;


class PoliceNode{
    private:
        stack<string> _subPilicy;
        stack<char> _attr;
        string _policy;
        int _threshold;
        int _policy_length;
        int _attr_count;
    public:
        PoliceNode(string policy);
        int getThreshold() const;
        void setThreshold(const int th);
        void print();
        void setAttr();
        int getPolicyLength() const;
        int getAttrCount() const;
        string getPolicy();
        stack <char> getAttr();
        stack<string> getSubPolicy();

};
#endif //_POLICY
