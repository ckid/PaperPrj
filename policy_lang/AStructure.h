#include <string>
#include "Policy.h"
#include <cmath>
using namespace std;
class AStructure{
    private:
        PoliceNode _policy;
        vector <char> _attrNode;
        vector <vector <int> >  _matrix;
        void insertPolicy(PoliceNode subPolicy);
        vector <vector <int> > getShareMatrix(const PoliceNode subPolicy);
    public:
        AStructure(string policy);
        vector <vector <int> > getMatrix();
        void toMatrix();
};


AStructure::AStructure(PoliceNode policy):_matrix(policy.getPolicyLength()), _attrNode(){
    this->_policy = policy;

}

void AStructure::toMatrix(){

}

void AStructure::insertPolicy(const PoliceNode subPolicy){
    pair< int, int> oriMarixSize(_matrix.size(), _matrix[0].size());
    _matrix.resize(_matrix.size() + subPolicy.getPolicyLength() - 1, vector<int>a(_matrix[0].size() + subPolicy.getAttrCount(), 0));
    vector<vector<int>> ::iterator  i = _matrix.begin();
    while (i < i + oriMarixSize.first){
        for (int j = 0; j < subPolicy.getAttrCount() -1; j ++){
            //padding the line above the new line;

        }
    }

}

 vector<vector<int>> AStructure::getShareMatrix(const PoliceNode subPolicy){
    vector< vector<int>> subMatrix(subPolicy.getPolicyLength(), vector<int>(0));
    vector< vector<int>> ::iterator  i = subMatrix.begin();
    int indexM = 1;
    while(i != subMatrix.end()){
        for (int j = 0; j < subPolicy.getAttrCount(); j++){
            *i.push_back(pow(indexM, *i.size()))
        }
        indexM ++;
    }
}
