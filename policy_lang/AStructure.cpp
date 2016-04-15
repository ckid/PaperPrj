#include "AStructure.h"
#include <iomanip>
#include <string>
AStructure::AStructure(string policy):_matrix(1, vector<int>(1,1)), _attrNode(), _policy(policy){
    this->_posIndex =0;

}

void AStructure::toMatrix(PoliceNode policy){
    // convert the policy to the matrix
    cout << "run to Matrix once!" <<endl;
    if (policy.getAttrCount() != policy.getPolicyLength())
    {
        // the policy has sub policy
        insertPolicy(policy, this->_posIndex);
        cout << "insert Policy" << policy.getPolicy()<<endl;
        //insert the attr to the p
        if(policy.getAttrCount() > 0){
            // attr has some naked attr
            stack<char> attrStack = policy.getAttr();
            while(!attrStack.empty()){
                this->_attrNode.insert(pair<char, int>(attrStack.top(), _posIndex));
                attrStack.pop();
                _posIndex++;
            }
        }
        stack<string> subPolicyStack(policy.getSubPolicy());
        while(!subPolicyStack.empty()){
        //tarcle the subPolicy
            PoliceNode subPolicy(subPolicyStack.top());
            cout << subPolicyStack.top();
            subPolicyStack.pop();
            subPolicy.setAttr();
            toMatrix(subPolicy);

        }
    } else {
    // no subpolicy
        insertPolicy(policy, this->_posIndex);
        stack<char> attrStack = policy.getAttr();
        while(!attrStack.empty()){
                this->_attrNode.insert(pair<char, int>(attrStack.top(), _posIndex));
                attrStack.pop();
                _posIndex++;
            }
    }
   // print();
}


vector<vector<int> > AStructure::getShareMatrix(const PoliceNode subPolicy){
    vector< vector<int> > subMatrix(subPolicy.getPolicyLength(), vector<int>(subPolicy.getThreshold(), 0));
    for (int i = 0; i < subPolicy.getPolicyLength(); i++){
        for (int j = 0; j <subPolicy.getThreshold(); j++){
            subMatrix[i][j] = calcPow(i+1,j);
           // cout <<endl<<"the content of the matrix is as follow:"<<i+1 <<':'<<j<< endl;
            // cout << subMatrix[i][j]<<endl;
        }
    }
    return subMatrix;
}

void AStructure::resizeMatrix(PoliceNode policy, int insertPos){
    //resize the matrix to fit the structure
    //vector <vector <int> >::iterator i = _matrix.begin();

    //if the capicity is not enouph  allow more
    int newSize = _matrix[0].size() + policy.getThreshold() - 1;
    cout<< "the new size of the matrix is " <<newSize<<endl;
    for (int i = 0; i < _matrix.size(); i++){
        _matrix[i].resize(newSize);
    }
    pair < int, int> policySize (policy.getPolicyLength(), policy.getThreshold());
    // insert place
    //vector <vector <int> > ::iterator pos = _matrix.begin() + insertPos; //  iterator unused
    for (int j = 0; j < policySize.first -1; j++){
        //insert policySize.first -1 line to the matrix
        _matrix.insert(_matrix.begin() + insertPos, _matrix[insertPos] );
    }
    cout <<  _matrix.size();
}

void AStructure::insertPolicy(const PoliceNode subPolicy, int attrPos){
    resizeMatrix(subPolicy, attrPos);
    vector < vector <int> > policyMatrix = getShareMatrix(subPolicy);
    pair <int, int> matrixSize(_matrix.size(), _matrix[0].size());
    //insert the new policy in the orignal matrix
    vector < vector <int> > ::iterator pos = _matrix.begin() + attrPos;
    for (int i = 0 ; i < subPolicy.getPolicyLength(); i ++){
        for (int j = subPolicy.getThreshold() -1; j >0; j --){
            (*pos)[matrixSize.second -j ] = policyMatrix[i][subPolicy.getThreshold() - j ];
        }
        pos ++;
    }
}

vector <vector<int> > AStructure::getMatrix(){
    return _matrix;
}

void AStructure::print(){
    cout << "The matrix of the policy is as follow:" << endl;
    vector < vector<int> > ::iterator i = _matrix.begin();
    while(i != _matrix.end()){
        for (vector<int> ::iterator j = (*i).begin(); j != (*i).end(); j++){
            cout << setw(10) << *j;
        }
        cout << endl;
        i++;
    }
    cout << "the map alg is as follow:" << endl;
    map<char, int>::iterator setIterator = _attrNode.begin();
    while (setIterator != _attrNode.end()){
        cout << setIterator->first<< ':' << setIterator->second <<endl;
        setIterator ++;
    }
}

int AStructure::calcPow(int i, int j){
    if (!j){
        return 1;
    } else{
        if (!i){
            return 0;
        }else{
            for(int t = 0; t < j-1; t++){
                i *= i;
            }
            return i;
        }
    }

}
