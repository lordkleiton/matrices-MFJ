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
        (m[i] < 10) ? cout << " " << m[i] << " " : cout << m[i] << " ";
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
        case 0: //x
            m = {   1, 0, 0, 0,
                    0, cos(a), -sin(a), 0,
                    0, sin(a), cos(a), 0,
                    0, 0, 0, 1};
            break;
        case 1: //y
            m = {   cos(a), 0, sin(a), 0,
                    0, 1, 0, 0,
                    -sin(a), 0, cos(a), 0,
                    0, 0, 0, 1};
            break;
        case 2: //z
            m = {   cos(a), -sin(a), 0, 0,
                    sin(a), cos(a), 0, 0,
                    0, 0, 1, 0,
                    0, 0, 0, 1};
            break;
    }

    vetor r = transformaPonto3d(m, v1);

    return r;
}

vetor rotacaoEixoQualquer(real angulo, vetor v){
    vetor rx = rotacao(angulo, 0, v);
    vetor ry = rotacao(angulo, 1, rx);
    vetor rz = rotacao(angulo, 2, ry);
    vetor riy = rotacao(-angulo, 1, rz);
    vetor rix = rotacao(-angulo, 0, riy);

    return rix;
}

void printVetor(vetor v){
    std::vector<string> aux = {"x", "y", "z"};

    for (int i = 0; i < 3; i++){
        cout << aux[i] << ": " << v[i] << endl;
    }
}

int main(int argc, char const *argv[]){
    vetor a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
    vetor b = {25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    vetor ponto = {45, 125, 4, 1};
    vetor vtranslacao = {200, 1250, 100, 1};
    vetor vescala = {2, 1.5, 5, 1};
    real angulo = 45;
    int d = 5;

    cout << "matriz a" << endl;
    prettyPrint(a, d);
    cout << endl;
    cout << "transposta de a" << endl;
    vetor resultado = transposta(a, d);
    prettyPrint(resultado, d);
    cout << endl;
    cout << "matriz b" << endl;
    prettyPrint(b, d);
    cout << endl;
    cout << "transposta de b" << endl;
    resultado = transposta(b, d);
    prettyPrint(resultado, d);
    cout << endl;
    cout << "a multiplicada por b" << endl;
    resultado = multiplica(a, b, d);
    prettyPrint(resultado, d);
    cout << endl;
    cout << "b multiplicada por a" << endl;
    resultado = multiplica(b, a, d);
    prettyPrint(resultado, d);
    cout << endl;
    cout << "b multiplicada por a" << endl;
    resultado = multiplica(b, a, d);
    prettyPrint(resultado, d);
    cout << endl;
    cout << "matriz identidade de dimensão " << d << endl;
    resultado = identidade(d);
    prettyPrint(resultado, d);
    cout << endl;
    cout << "vetor ponto" << endl;
    printVetor(ponto);
    cout << endl;
    cout << "vetor que vai transladar o vetor ponto" << endl;
    printVetor(vtranslacao);
    cout << endl;
    cout << "ponto após translação" << endl;
    resultado = translacao(ponto, vtranslacao);
    printVetor(resultado);
    cout << endl;
    cout << "vetor que vai escalar o vetor ponto" << endl;
    printVetor(vescala);
    cout << endl;
    cout << "ponto após escalonamento" << endl;
    resultado = escala(ponto, vescala);
    printVetor(resultado);
    cout << endl;
    cout << "angulo de rotação " << endl;
    cout << angulo << " graus" << endl;
    cout << endl;
    cout << "vetor ponto rotacionado no eixo x por " << angulo << " graus" << endl;
    resultado = rotacao(angulo, 0, ponto);
    printVetor(resultado);
    cout << endl;
    cout << "vetor ponto rotacionado no eixo y por " << angulo << " graus" << endl;
    resultado = rotacao(angulo, 1, ponto);
    printVetor(resultado);
    cout << endl;
    cout << "vetor ponto rotacionado no eixo z por " << angulo << " graus" << endl;
    resultado = rotacao(angulo, 2, ponto);
    printVetor(resultado);
    cout << endl;
    cout << "vetor ponto rotacionado em eixo qualquer por " << angulo << " graus" << endl;
    resultado = rotacaoEixoQualquer(angulo, ponto);
    printVetor(resultado);

    return 0;
}