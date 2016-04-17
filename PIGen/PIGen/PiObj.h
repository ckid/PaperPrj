#ifndef _PIOBJ
#define _PIOBJ
#include <NTL/mat_ZZ_p.h>
#include <iostream>
#include <NTL/ZZ.h>
#include <NTL/ZZ_p.h>
#include <NTL/vector.h>
#include <map>

class PiObj {
    public:
        PiObj();
        pair<int, ZZ> genSec();
        void genPI();
        Vec<ZZ_p> getACV();
        void setKet(int index, ZZ key);

    private:
        Vec<ZZ_p> _ACV;
        Mat<ZZ_p> _secMatrix;
        ZZ  _sysVer;
        long _strLen;
        int _groupSize;
        Vec<ZZ> _randPara;
        Vec<ZZ> _resultVec;
        map<int, ZZ> _keyVec;
        map< int, ZZ > _secVec;
        ZZ genSeed();
        void ACVCalc();
        ZZ genHash(const ZZ sec, const ZZ ranZ);

};

#endif // _PIOBJ
