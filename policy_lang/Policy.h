#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


class PoliceNode{
    private:
        stack<string> _subPilicy;
        stack<char> _attr;
        string _policy;
        int _threshold;
        int _policy_length;
    public:
        PoliceNode(string policy);
        int getThreshold() const;
        void setThreshold(const int th);
        void setAttr();
        void print();
        int getPolicyLength() const;

};

PoliceNode::PoliceNode(string policy): _subPilicy(), _attr(), _threshold(0){
    _policy = policy;
    _policy_length = 0;
}

inline int PoliceNode::getThreshold() const{
    return _threshold;
}

inline void PoliceNode::setThreshold(const int th){
    _threshold = th;
}

void PoliceNode::setAttr(){
    stack<char> policyChar;
    int policyObjCount = 0;
    for (int i = 1; i < this->_policy.length(); i++){
    // the first ( was not pushed to the stack
        if(_policy[i] == '('){
            policyObjCount ++;
        }
        policyChar.push(_policy[i]);
    }
    // all the node are push to the stack
    if(policyObjCount == 0){
        //the node is the final node
        policyChar.pop();
        this->_threshold = policyChar.top();
        policyChar.pop();
        char fragment;
        while (!policyChar.empty()){
            fragment = policyChar.top();
            policyChar.pop();
            if (fragment != ','){
                 _attr.push(fragment);
                 _policy_length++;
            }
        }
    } else{
        //the policy has subpolicy
        policyChar.pop();
        this->_threshold = policyChar.top();
        policyChar.pop();
        char fragment ;
        while (!policyChar.empty()){
            fragment = policyChar.top();
            policyChar.pop();
            if (')' == fragment){
                //find an subpolicy
                _policy_length++;
                string subPolicy = ")";
                int layerCount = 1;
                while(layerCount != 0){
                    fragment = policyChar.top();
                    policyChar.pop();
                    if (fragment == ')'){
                        layerCount ++;
                    }
                    if (fragment == '('){
                        layerCount --;
                    }
                    subPolicy += fragment;
                }

                reverse(subPolicy.begin(), subPolicy.end());
                this->_subPilicy.push(subPolicy);
            } else if ( fragment != ',' and fragment != '('){
                _policy_length++;
                _attr.push(fragment);
            }
        }
    }
}

inline int PoliceNode::getPolicyLength() const{
    return _policy_length;
}

void PoliceNode::print(){
    cout << _policy<<endl;
    cout << "The attr in the attribute is as follows:" << endl;
    while(!_attr.empty()){
        cout << _attr.top();
        cout << "<-->";
        _attr.pop();
    }
    cout << "The threshold of the policy is " << _threshold<< endl;

    cout << "subPolicy is as follows:" << endl;
    while (!_subPilicy.empty()){
        cout << _subPilicy.top() << ":";
        _subPilicy.pop();

    }
}
