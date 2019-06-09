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

    /* for (int i = 0; i < r.size(); i++){
        for (int j = 0; i < r.size(); i++){

        }
    } */

    return r;
}

std::vector<real> transposta(std::vector<real> m, int d){
    std::vector<real> r(d * d);
    int c = 0;
    int a = 0;

    for (int i = 0; i < d; i++){
        for (int j = 0; j < d; j++){
            if (c > (d * d - 1)) c = 0;

            r[c+i] = m[i + j + a];

            c += d;
        }

        a += d - 1;
    }

    return r;
}

int main(int argc, char const *argv[]){
    /* int d = 0;
    cout << "dimensoes (2, 3 ou 4): " << endl;
    cin >> d;

    while (d < 2 || d > 4) cin >> d;

    cout << "primeira matriz: " << endl;
    vetor m1 = input(d);

    cout << "segunda matriz: " << endl;
    vetor m2 = input(d);

    cout << "m1:" << endl;
    prettyPrint(m1, d);

    cout << endl;

    cout << "m2:" << endl;
    prettyPrint(m2, d);

    cout << endl; */

    //vetor m3 = mult(m1, m2, d);
    int d = 3;
    vetor m1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    //vetor m1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

    prettyPrint(m1, d);

    vetor m3 = transposta(m1, d);
    prettyPrint(m3, d);


    return 0;
}