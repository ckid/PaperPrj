#include "Policy.h"
#include <cstdlib>
PoliceNode::PoliceNode(string policy): _subPilicy(), _attr(), _threshold(0){
    _policy = policy;
    _policy_length = 0;
    _attr_count =0;
}

int PoliceNode::getThreshold() const{
    return _threshold;
}

void PoliceNode::setThreshold(const int th){
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
        this->_threshold = policyChar.top() - '0';
        policyChar.pop();
        char fragment;
        while (!policyChar.empty()){
            fragment = policyChar.top();
            policyChar.pop();
            if (fragment != ','){
                 _attr.push(fragment);
                 _policy_length++;
                 _attr_count++;
            }
        }
    } else{
        //the policy has subpolicy
        policyChar.pop();
        this->_threshold = policyChar.top() - '0';
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
                _attr_count++;
                _attr.push(fragment);
            }
        }
    }
}

int PoliceNode::getPolicyLength() const{
    return _policy_length;
}

int PoliceNode::getAttrCount() const{
    return _attr_count;
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

stack<char> PoliceNode::getAttr(){
    return _attr;

}

stack<string> PoliceNode::getSubPolicy(){
    return _subPilicy;
}

string PoliceNode::getPolicy(){
    return _policy;
}
