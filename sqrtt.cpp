#include <cmath>
#include <iostream>

using namespace std;

double sqrtt(double x, int precise){
    double s = 0;
    double e = x + 1;
    double p = pow(0.1, precise);
    while(e - s > p){
        double m = (s + e) / 2;
        if(m*m < x)
            s = m;
        else
            e = m;
    }
    return e;
    
}

int main(int argc, const char * argv[]) {
    cout << sqrtt(4, 2);
    return 0;
}
