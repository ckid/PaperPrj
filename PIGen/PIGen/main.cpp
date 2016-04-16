#include <iostream>
#include <NTL/mat_ZZ_p.h>
#include <NTL/ZZ.h>
#include <time.h>


using namespace std;
using namespace NTL;

int main(){
    ZZ p ;
    ZZ a, b;
    p = to_ZZ("8780710799663312522437781984754049815806883199414208211028653399266475630880222957078625179422662221423155858769582317459277713367317481324925129998224791");
    ZZ_p::init(p);
    ZZ sed ;
    sed = to_ZZ(time(NULL));
    SetSeed(sed);
    RandomLen(a, 100);
    RandomLen(b, 100);
    cout << a <<endl;
    cout << b <<endl;
    cout <<p<<endl;
}
