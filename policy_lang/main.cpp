#include <iostream>
#include "Policy.h"
#include "AStructure.h"
using namespace std;

int main()
{
    PoliceNode policy("((A,B,C,2),(D,E,F,2),(G,H,(I,J,K,L,3),2),2)");
    policy.setAttr();
    //policy.print();
    AStructure LSSS("((A,B,C,2),(D,E,F,2),(G,H,(I,J,K,L,3),2),2)");
    LSSS.toMatrix(policy);
    LSSS.getMatrix();
    LSSS.print();
    return 0;
}
