#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>

using namespace std;

typedef double real;
typedef vector<real> vetor;
typedef vector<vetor> matriz;

void prettyPrint(vetor m, int d){
    for (int i = 0; i < m.size(); i++){
        if (i % d == 0) cout << "| ";
        cout << m[i] << " ";
        if ((i+1) % d == 0) cout << "|" << endl;
    }
}

vetor input(int d){
    vetor m(d * d);

    for (int i = 0; i < m.size(); i++)
        cin >> m[i];

    return m;
}

matriz converteArrayMatriz(vetor m, int d){
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

vetor converteMatrizArray(matriz m, int d){
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

vetor multiplica(vetor m1, vetor m2, int d){
    vetor r(d * d);
    matriz aux1 = converteArrayMatriz(m1, d);
    matriz aux2 = converteArrayMatriz(m2, d);
    matriz aux3(d, vetor(d));

    for (int i = 0; i < d; i++){
        for (int j = 0; j < d; j++){
            for (int k = 0; k < d; k++){
                aux3[i][j] += aux1[i][k] * aux2[k][j];
            }
        }
    }

    r = converteMatrizArray(aux3, d);

    return r;
}

vetor transposta(vetor m, int d){
    vetor r(d * d);
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

vetor transformaPonto3d(vetor v1, vetor v2){
    vetor r(4);
    int aux = 0;

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            r[i] += v1[aux + i + j] * v2[j];
        }
        aux += 3;
    }

    return r;
}

vetor identidade(int d){
    vetor r(d * d);
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
    int aux = 0;

    vetor r = transformaPonto3d(m, v2);

    return r;
}

vetor translacao(vetor v1, vetor v2){
    vetor m = { 1, 0, 0, v1[0],
                0, 1, 0, v1[1],
                0, 0, 1, v1[2],
                0, 0, 0, 1};
    int aux = 0;

    vetor r = transformaPonto3d(m, v2);

    return r;
}

vetor rotacao(real angulo, int eixo, vetor v1){
    vetor m(16);
    real a = angulo * M_PI / 180;
    int aux = 0;

    switch (eixo){
        case 0:
            m = {   1, 0, 0, 0,
                    0, cos(a), -sin(a), 0,
                    0, sin(a), cos(a), 0,
                    0, 0, 0, 1};
            break;
        case 1:
            m = {   cos(a), 0, sin(a), 0,
                    0, 1, 0, 0,
                    -sin(a), 0, cos(a), 0,
                    0, 0, 0, 1};
            break;
        case 2:
            m = {   cos(a), -sin(a), 0, 0,
                    sin(a), cos(a), 0, 0,
                    0, 0, 1, 0,
                    0, 0, 0, 1};
            break;
    }

    vetor r = transformaPonto3d(m, v1);

    return r;
}

int main(int argc, char const *argv[]){
    vetor a = {2, 0.5, 2, 1};
    vetor b = {45, 125, 4, 1};

    //vetor v6 = escala(a, b);
    //vetor v6 = translacao(a, b);
    vetor v = rotacao(45, 0, b);
    prettyPrint(v, 4);

    vetor v2 = {1, 2, 3, 4};
    vetor v3 = {4, 3, 2, 1};

    vetor v5 = multiplica(v2, v3, 2);
    prettyPrint(v5, 2);

    return 0;
}