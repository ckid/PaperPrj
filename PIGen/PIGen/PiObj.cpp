#include "PiObj.h"
#include <openssl/sha.h>
#include <string.h>

PiObj::PiObj(const int groupSize, const long strLen, ZZ& p):_randPara(groupSize), _resultVec(groupSize), _secVec(0){
    this->_groupSize = groupSize;
    this-> _sysVer = p;
    this-> _strLen = strLen;
    //generate  the random vector to use generate the A
    SetSeed(genSeed());
    ZZ tmp;
    ZZ_p::init(p);
    for (int i = 0; i < _groupSize; i++){
        RandomLen(tmp, this->_strLen);
        this->_randPara.push_back(tmp);
    }
}

ZZ PiObj::genSec(int index){
    //  gen secret for user
    SetSeed(genSeed());
    ZZ randomStr ;
    RandomLen(randomStr, this->_strLen)
    pair< int, ZZ > sec(index, sec);
    _secVec.push_back(sec);
    return sec;

}


ZZ PiObj::genSeed(int index){
    ZZ sed(to_ZZ(time(NULL)));
    return sed;
}

Vec<ZZ_p> PiObj::getACV(){
    return _ACV;
}

void PiObj::genSecMatrix(){
    for (int i = 0, i < _groupSize; i ++){
        for(int j = 0, j < 2* _groupSize; j ++){
            if (i == j){
                _secMatrix[i][j] = 1;
            } else if (0 <= i && i <= _groupSize){
                _secMatrix[i][j] = 0;
            } else{
                ZZ sec = _secVec.find(i)->second;
                _secMatrix[i][j] = getHash(sec, _randPara[j])
            }
        }
    }
}

void PiObj::genHash(const ZZ sec, const ZZ ranZ){
    unsigned char * secStr, ranZStr;
    BytesFromZZ(secStr, sec, _strLen);
    BytesFromZZ(ranZStr, ranZ, _strLen);
    unsigned char * shaSrc = strcat(secStr, ranZStr);
    unsigned char[SHA512_DIGEST_LENGTH] shaRes;
    SHA512(shaSrc, 2*_strLen, shaRes);
    return ZZFromBytes(shaRes, _strLen);
}

void PiObj::ACVCalc(){

    //generate an random vector;
    vec_ZZ_p randVar(2* _groupSize);
    vec_ZZ_p result(2* _groupSize, 0);
    SetSeed(genSeed());
    for (int i = 0; i < _groupSize; i++){
        randVar[i] = RandomBnd(_sysVer);
    }
    //calc the Y
    for (int i= 0; i < 2* _groupSize; i ++){
        ZZ_p tmp_val = 0;
        if (i < _groupSize){
            for ( int j = 0; j < _groupSize; j ++){
                tmp_val += randVar[i] * this->_secMatrix[i][j + _groupSize];
            }
            result[i] = tmp_val;
        } else{
            result[i] = randVar[i];
        }
    }

    //generate
    for (int i = 0; i < _groupSize; i++){
        result[i] += _keyVec.find(i)->second;
    }
}

void PiObj::setKey(int index, ZZ key){
    _keyVec.insert(pair <int, ZZ>(index, key));
}

