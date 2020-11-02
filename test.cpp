#include <ctime>
#include <iostream>
#include <cmath>
using namespace std;
typedef unsigned long long ull;

double sigmoid(ull x){
    return 1.0/(1+exp(-x));
}
double mysigmoid(ull x){
    if(x>0){
        ull n=1ULL<<x;
        return (double)n/(1+n);
    }
    else return 1.0/((1ULL<<-x)+1);
}
int main(){
    ull repeat = 100000000; //repeat회 반복한다.
    clock_t _start;
    clock_t _end;

    _start = clock();
    for(ull i=0;i<repeat;++i)sigmoid(i);
    _end = clock();
    double orig = _end-_start;

    _start = clock();
    for(ull i=0;i<repeat;++i)mysigmoid(i);
    _end = clock();
    double mine = _end-_start;

    cout<<"original: "<<orig<<"ms\n";
    cout<<"mine:"<<mine<<"ms\n";
}
