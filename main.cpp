#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef double real;
typedef vector<real> vetor;
typedef vector<vetor> matriz;

void prettyPrint(std::vector<real> m, int d){
    for (int i = 0; i < m.size(); i++){
        if (i % d == 0) cout << "| ";
        cout << m[i] << " ";
        if ((i+1) % d == 0) cout << "|" << endl;
    }
}

std::vector<real> input(int d){
    std::vector<real> m(d * d);

    for (int i = 0; i < m.size(); i++)
        cin >> m[i];

    return m;
}

std::vector<std::vector<real>> converteAM(std::vector<real> m, int d){
    matriz r(d, vetor(d));
    int a = 0;

    for (int i = 0; i < d; i++){
        for (int j = 0; j < d; j++){
            r[i][j] = m[a + i + j];
        }

        a += d - 1;
    }

    return r;
}

std::vector<real> converteMA(std::vector<std::vector<real>> m, int d){
    vetor r(d * d);
    int a = 0;

    for (int i = 0; i < d; i++){
        for (int j = 0; j < d; j++){
            r[a + i + j] = m[i][j];
        }

        a += d - 1;
    }

    return r;
}

std::vector<real> mult(std::vector<real> m1, std::vector<real> m2, int d){
    std::vector<real> r(d * d);
    std::vector<std::vector<real>> aux1 = converteAM(m1, d);
    std::vector<std::vector<real>> aux2 = converteAM(m2, d);
    std::vector<std::vector<real>> aux3(d, std::vector<real>(d));

    for (int i = 0; i < d; i++){
        for (int j = 0; j < d; j++){
            for (int k = 0; k < d; k++){
                aux3[i][j] += aux1[i][k] * aux2[k][j];
            }
        }
    }

    r = converteMA(aux3, d);

    return r;
}

std::vector<real> transposta(std::vector<real> m, int d){
    std::vector<real> r(d * d);
    int c = 0;
    int a = 0;

    for (int i = 0; i < d; i++){
        for (int j = 0; j < d; j++){
            if (c > (d * d - 1)) c = 0;

            r[c + i] = m[i + j + a];

            c += d;
        }

        a += d - 1;
    }

    return r;
}

std::vector<real> identidade(int d){
    std::vector<real> r(d * d);
    int ponto = 0;

    for (int i = 0; i < r.size(); i++){
        if (ponto > (r.size() - 1)) ponto = 0;
        r[ponto] = 1;
        ponto += d + 1;
    }

    return r;
}

vetor escala(vetor v1, vetor v2){
    vetor m = {v1[0], 0, 0, 0,
                0, v1[1], 0, 0,
                0, 0, v1[2], 0,
                0, 0, 0, 1};
    vetor r(4);
    int aux = 0;

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            r[i] += m[aux + i + j] * v2[j];
        }
        aux += 3;
    }

    return r;
}

vetor translacao(vetor v1, vetor v2){
    vetor m = { 1, 0, 0, v1[0],
                0, 1, 0, v1[1],
                0, 0, 1, v1[2],
                0, 0, 0, 1};
    vetor r(4);
    int aux = 0;

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            r[i] += m[aux + i + j] * v2[j];
        }
        aux += 3;
    }

    return r;
}

int main(int argc, char const *argv[]){
    vetor aa = {2, 0.5, 2, 1};
    vetor bb = {45, 125, 4, 1};

    //vetor v6 = escala(aa, bb);
    //vetor v6 = translacao(aa, bb);
    vetor v6 = escala(aa, bb);
    prettyPrint(v6, 4);

    int hm = -1;

    cout << -hm << endl;

    return 0;
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
    /* int d = 2;
    vetor m1 = {0, 1, 2, 3};//, 5, 6, 7, 8, 9};
    vetor m2 = {0, */ //1, 2, 3};//, 5, 6, 7, 8, 9};

    //vetor m1 = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    //vetor m2 = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    //vetor m1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

    /* prettyPrint(m1, d);
    cout << endl */;

    //vetor m3 = transposta(m1, d);
    //vetor m3 = mult(m1, m2, d);
    //prettyPrint(m3, d);
    /* 
    cout << endl;

    vetor v5 = identidade(5);
    prettyPrint(v5, 5);
    cout << endl; */

    
}