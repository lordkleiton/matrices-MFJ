#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef double real;
typedef vector<real> vetor;

void prettyPrint(std::vector<real> m, int d){
    for (int i = 0; i < m.size(); i++){
        if (i % d == 0) cout << "| ";
        cout << m[i] << " ";
        if ((i+1) % d == 0) cout << "|" << endl;
    }
}

std::vector<real> input(int d){
    std::vector<real> m(d*d);

    for (int i = 0; i < m.size(); i++)
        cin >> m[i];

    return m;
}

std::vector<real> mult(std::vector<real> m1, std::vector<real> m2, int d){
    std::vector<real> r(d * d);

    for (int i = 0; i < r.size(); i++){
        
    }

    return r;
}

int main(int argc, char const *argv[]){
    int d = 0;
    cout << "dimensoes: " << endl;
    cin >> d;

    cout << "primeira: " << endl;
    vetor m1 = input(d);

    cout << "segunda: " << endl;
    vetor m2 = input(d);

    cout << "m1:" << endl;
    prettyPrint(m1, d);

    cout << endl;

    cout << "m2:" << endl;
    prettyPrint(m2, d);

    cout << endl;

    vetor m3 = mult(m1, m2, d);
    prettyPrint(m3, d);


    return 0;
}