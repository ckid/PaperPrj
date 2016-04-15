#include "Policy.h"
#include <string>
#include <cmath>
#include <map>
#ifndef _ASTRUCTURE
#define _ASTRUCTURE
using namespace std;
class AStructure{
    private:
        PoliceNode _policy;
        int _posIndex;
        map <char, int> _attrNode;
        vector <vector <int> >  _matrix;
        void resizeMatrix(PoliceNode policy, int insertPos);
        void insertPolicy(PoliceNode subPolicy, int insertPos);
        vector <vector <int> > getShareMatrix(const PoliceNode subPolicy);
        int calcPow(int i, int j);
    public:
        AStructure(string policy);
        vector <vector <int> > getMatrix();
        void toMatrix(PoliceNode policy);
        void print();


};

#endif // _ASTRUCTURE
