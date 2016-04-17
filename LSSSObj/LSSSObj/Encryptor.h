#ifndef _DECRYPTOR
#define _DECRYPTOR
#include <iostream>
#include <string>
#include <vector>
#include <NTL/ZZ.h>
#include <NTL/vec_ZZ.h>
#include <NTL/mat_ZZ.h>
#include "Policy.h"
#include "AStructure.h"

using namespace std;
class Encryptor {
    public:
        Encryptor();
        PolicyNode _policy;
        AStructure _ASObject;
        vector <vector<int> > _policyMatrix;
        void updatePolicy(string polcy);
        vec_ZZ genMediaKey(long keySize, int userIndex);
        int regAttr(vector<char> userAttrVec);

    private:
        mat_ZZ _mediaKey;
        ZZ _shareKey;
        long _keyLen;
        vector < <char> > _userAttrMatrix;
        void genSecKey();
};

#endif
