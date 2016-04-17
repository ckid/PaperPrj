#include "Decryer.h"


Decryer::Decryer(pair<int,ZZ> secret, vec_ZZ ran, ZZ p): _secret(secret), _ranSysVar(ran){
    this->_p = p;
    ZZ_p::init(p);
}

vec_ZZ Decryer::genUserVec(){
    vec_ZZ userVec(2*_groupSize);
    for (int i =0; i < 2 * _groupSize; i++){
        if(_secret.first == i){
            userVec[i] = 1;
        } else if(0 <= i && i <= _groupSize){
            userVec[i] = 0;
        } else {
            userVec[i] = genHash(_secret.second, _ranSysVar[i - _groupSize]);
        }
    }

    return userVec;
}

ZZ Decryer::genHash(const ZZ sec, const ZZ ranZ){
    unsigned char * secStr, ranZStr;
    BytesFromZZ(secStr, sec, _strLen);
    BytesFromZZ(ranZStr, ranZ, _strLen);
    unsigned char * shaSrc = strcat(secStr, ranZStr);
    unsigned char[SHA512_DIGEST_LENGTH] shaRes;
    SHA512(shaSrc, 2*_strLen, shaRes);
    return ZZFromBytes(shaRes, _strLen);
}


ZZ Decryer::keyDer(vec_ZZ publicInfor){
    return publicInfor * genUserVec();
}
