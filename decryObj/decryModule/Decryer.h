#ifdef _DECRYER
#define _DECRYER

#include<NTL/ZZ.h>
#include<NTL/ZZ_p.h>
#include<NTL/mat_ZZ_p.h>
#include<NTL/vec_ZZ.h>

class Decryer{
    public:
        void Decryer();
        void setPI(const vec_ZZ& ACV, const vec_ZZ& ranVar);
    private:
        pair<int, ZZ> _secret;
        vec_ZZ _ranSysVar;
        ZZ _p;
        long _groupSize;
        vec_ZZ genUserVec();
        ZZ genHash(const ZZ sec, const ZZ ranZ);
        ZZ keyDir(vec_ZZ& publicInfo)
};

#endif // _DECRYER
