#include "Encryptor.h"
#include <vector>
#include <time.h>

Encryptor::Encryptor(string policy):_policy(policy),_ASObject(policy){
        this->_policy.setAttr();
        this->_ASObjec.toMatrix(_polcy);
}

void Encryptor::updatePolicy(string policy),{
    PolicyNode newPolicy(poilcy);
    newPolicy.setAttr();
    this->_policy(newPolicy);
    AStructure newASobj(policy);
    newASobj.toMatrix(this->_policy);
}

int Encryptor::regAttr(vector <char>& userAttrVec){
    vector<char> userVector(_ASObject._attrNode.size(), '0');
    for(vector<char>::iterator i = userAttrVec.begin(); i != userAttrVec.end(); i++){
        userVector[_ASObject._attrNode.find(*i).second] = *i;
    }
    _userAttrMatrix.push_back(userVector);
    return _userAttrMatrix.size() -1;
}

void Encryptor::genMediaKey(long keySize, int userIndex){
    int vecSize = (_ASObject._matrix)[0].size();
    vec_ZZ userRanVec(vecSize);
    vec_ZZ mediaKeyVec(vecSize, 0);
    ZZ sed(to_ZZ(time(NULL)));
    SetSeed(sed);
    for (int i = 1; i < vecSize; i++){
        userRanVec[i] = RandomBits(this->keyLen);
    }
    userRanVec[0] = _shareKey;
    //gen MediaKey
    for (int i = 0; i < vecSize; i++){
        char tmpAttr = _userAttrMatrix[index][i];
        if (tmpAttr != '0'){
            //user i has the attribute generate the
            ZZ userMediaKey;
            int policyIndex = _ASObject._attrNode.find(tmpAttr).second;
            for (int j = 0; j < vecSize; j ++){
                userMediaKey += userRanVec[j] * _ASObject._matrix[policyIndex][j]
            }
            mediaKeyVec[i] = userMediaKey;

        }
    }
    _mediaKey.push_back(mediaKeyVec);

}

void Encryptor::genSecKey(){
    ZZ sed(to_ZZ(time(NULL)));
    SetSeed(sed);
    _shareKey = RandomBits_ZZ(_keylen);
}
