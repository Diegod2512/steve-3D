#include "sculptor.h"
#include<iostream>
#include<fstream>
#include<iomanip>
#include<cmath>
#include<vector>
#include<queue>
#include<string>
using namespace std;

Sculptor::Sculptor(int mx, int my, int mz){ //Construtor que vai alocar a matriz
    nx = mx; ny = my; nz = mz;
    lado = 0.5;
    aloca();
    apoio();
}

Sculptor::~Sculptor(){
    libera();
}

void Sculptor::aloca(){
    v = new Voxel**[nx];
    for (i = 0; i < nx; i++){
        v[i] = new Voxel * [ny];
    }
    for (i = 0; i < nx; i++){
        for (int j = 0; j < ny; j++){
            v[i][j] = new Voxel[nz];
        }
    }
    for (i = 0; i < nx; i++){
        for (j = 0; j < ny; j++){
            for (k = 0; k < nz; k++){
                v[i][j][k].isOn = false;
            }
        }
    }
}

void Sculptor::libera(){
    delete [] v;
}

void Sculptor::troca(int &a, int &b){
    int tmp;
    tmp = a; a = b; b = tmp;
}

void Sculptor::preenche(int x0, int x1, int y0, int y1, int z0, int z1){
    //função que vai procurar por blocos em um determinado espaço e se os isOn deles for falso,
    //a função torna verdadeiro e pinta de preto
    setColor(0.0,  0.0, 0.0, 1.0);
    for (int i = x0; i < x1; i++){
        for (int j = y0; j < y1; j++){
             for (int k = z0; k < z1; k++){
                 if (v[i][j][k].isOn == false){
                     v[i][j][k].isOn = true;
                 }
             }
        }
    }
}

void Sculptor::setColor(float mr, float mg, float mb, float alpha){
    r = mr; g = mg; b = mb; a = alpha;
}

void Sculptor::putVoxel(int x, int y, int z){

    v[x][y][z].isOn = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
}

void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].isOn = false;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){

    //finais > iniciais...
    while (true){
        if (x0 > x1){
            troca(x0, x1);
        }
        if (y0 > y1){
            troca(y0, y1);
        }
        if (z0 > z1){
            troca(z0, z1);
        }
        break;
    }

    //colocando a box
    for (i = x0; i < x1; i++){
        for (j = y0; j < y1; j++){
            for (k = z0; k < z1; k++){
                v[i][j][k].isOn = true;
                v[i][j][k].r = r;
                v[i][j][k].g = g;
                v[i][j][k].b = b;
                v[i][j][k].a = a;
            }
        }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    //finais > iniciais...
    while (true){
        if (x0 > x1){
            troca(x0, x1);
        }
        if (y0 > y1){
            troca(y0, y1);
        }
        if (z0 > z1){
            troca(z0, z1);
        }
        break;
    }
    //tiranso a caixa
    for (int i = x0; i < x1; i++){
        for (int j = y0; j < y1; j++){
            for (int k = z0; k < z1; k++){
                v[i][j][k].isOn = false;
            }
        }
    }
}
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    float dx, dy, dz;
    for (int i = 0; i < nx; i++){
        for (int j = 0; j < ny; j++){
            for (int k = 0; k < nz; k++){
                dx = pow (i - xcenter, 2);
                dy = pow (j - ycenter, 2);
                dz = pow (k - zcenter, 2);
                if ((dx + dy + dz) < pow(radius, 2)){
                    v[i][j][k].isOn = true;
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    float dx, dy, dz;
    for (int i = 0; i < nx; i++){
        for (int j = 0; j < ny; j++){
            for (int k = 0; k < nz; k++){
                dx = pow (i - xcenter, 2);
                dy = pow (j - ycenter, 2);
                dz = pow (k - zcenter, 2);
                if ((dx + dy + dz) < pow(radius, 2)){
                    v[i][j][k].isOn = false;

                }
            }
        }
    }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){

    float dx, dy, dz;
    int cx, fx, cy, fy, cz, fz;

    while (true){
        if(xcenter > nx){
            xcenter = nx;
        }
        else{
            if (xcenter < 0){
                xcenter = 0;
            }
        }

        if(ycenter > ny){
            ycenter = ny;
        }
        else{
            if (ycenter < 0){
                ycenter = 0;
            }
        }

        if(zcenter > nz){
            zcenter = nz;
        }
        else{
            if (zcenter < 0){
                zcenter = 0;
            }
        }

        if (xcenter-rx >=0){
            cx = xcenter-rx;
        }
        else{
            cx = 0;
        }

        if (ycenter-ry >=0){
            cy = ycenter-ry;
        }
        else{
            cy = 0;
        }

        if (zcenter-rz >=0){
            cz = zcenter-rz;
        }
        else{
            cz = 0;
        }

        if (xcenter+rx <= nx){
            fx = xcenter+rx;
        }
        else{
            fx = nx;
        }

        if (ycenter+ry <= ny){
            fy = ycenter+ry;
        }
        else{
            fy = ny;
        }

        if (zcenter+rz <= nz){
            fz = zcenter+rz;
        }
        else{
            fz = nz;
        }
        break;
    }

    for (i = cx; i < fx; i++){
        for (j = cy; j < fy; j++){
            for (k = cz; k < fz; k++){
                dx = pow((i-xcenter), 2)/(pow(rx, 2));
                dy = pow((j-ycenter), 2)/(pow(ry, 2));
                dz = pow((k-zcenter), 2)/(pow(rz, 2));
                if ((dx + dy + dz) < 1){
                    v[i][j][k].isOn = true;
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                }
            }
        }
    }

}
void Sculptor::apoio(){
    //cria blocos de apoio na origem e nas extremidades de cada eixo
    setColor(1.0, 1.0, 1.0, 0.2);   //branco
    putVoxel(0, 0, 0);              //origem
    setColor(1.0, 1.0, 0.0, 0.2);   //amarelo
    putVoxel(nx-1, 0, 0);           //eixo x
    setColor(0.0, 1.0, 0.0, 0.2);   //verde
    putVoxel(0, ny-1, 0);           //eixo y
    setColor(0.0, 0.0, 1.0, 0.2);   //azul
    putVoxel(0, 0, nz-1);           //eixo z
}

void Sculptor::bordas(){
    setColor(0.0, 0.0, 0.0, 1.0);
    PutBox(1, nx-1, 1, ny-1, 1, nz-1);   //colocando a caixa inteira
    CutBox(1, nx-1, 2, ny-2, 2, nz-2);   //tirando no eixo x
    CutBox(2, nx-2, 1, ny-1, 2, nz-2);   //tirando no eixo y
    CutBox(2, nx-2, 2, ny-2, 1, nz-1);   //tirando no eixo z
}

void Sculptor::corte(int x0, int x1, int y0, int y1, int z0, int z1){
    //Faz um corte em linhas e colunas
    for (int i = x0; i < x1; i++){
        for (int j = y0; j < y1; j++){
            for (int k = z0; k < z1; k++){
                if (i == x0 || i == x1-1 ||j == y0 || j == y1-1|| k == z0 || k == z1-1){
                    v[i][j][k].isOn = false;
                }
            }
        }
    }
}

void Sculptor::writeOFF(string filename){
    int face = 0;
    int total = 0;
    //declaração da variável 'escrever', que vai entrar no arquivo e escrever tudo aquilo que for necessário
    ofstream escrever;
    //abrindo o arquivo
    escrever.open(filename);
    //verificando o fluxo
    if (!escrever.is_open()){
                exit (0);
    }

    //contando o total de blocos que serão construídos
    //isso é importante para escrever o número de vértices e faces
    for (i = 0; i < nx; i++){
        for (j = 0; j < ny; j++){
            for (k = 0; k < nz; k++){
                if (v[i][j][k].isOn == true){
                   total++;
                }
            }
        }
    }

    //escreve o OFF no começo
    escrever << "OFF\n";
    escrever << total*8 << " " << total*6 << " 0\n";
    for (i = 0; i < nx; i++){
        for (j = 0; j < ny; j++){
            for (k = 0; k < nz; k++){
                if (v[i][j][k].isOn == true){
                    escrever << i - lado << " " << j + lado << " " << k - lado << endl;
                    escrever << i - lado << " " << j - lado << " " << k - lado << endl;
                    escrever << i + lado << " " << j - lado << " " << k - lado << endl;
                    escrever << i + lado << " " << j + lado << " " << k - lado << endl;
                    escrever << i - lado << " " << j + lado << " " << k + lado << endl;
                    escrever << i - lado << " " << j - lado << " " << k + lado << endl;
                    escrever << i + lado << " " << j - lado << " " << k + lado << endl;
                    escrever << i + lado << " " << j + lado << " " << k + lado << endl;
                }
            }
        }
    }
    for (i = 0; i < nx; i++){
        for (j = 0; j < ny; j++){
            for (k = 0; k < nz; k++){
                if (v[i][j][k].isOn == true){
                    escrever << 4 << " " << face + 0 << " " << face + 3 << " " << face + 2 << " " << face + 1 << " ";
                    escrever << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    //face 1
                    escrever << 4 << " " << face + 4 << " " << face + 5 << " " << face + 6 << " " << face + 7 << " ";
                    escrever << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    //face 2
                    escrever << 4 << " " << face + 0 << " " << face + 1 << " " << face + 5 << " " << face + 4 << " ";
                    escrever << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    //face 3
                    escrever << 4 << " " << face + 0 << " " << face + 4 << " " << face + 7 << " " << face + 3 << " ";
                    escrever << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    //face 4
                    escrever << 4 << " " << face + 3 << " " << face + 7 << " " << face + 6 << " " << face + 2 << " ";
                    escrever << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    //face 5
                    escrever << 4 << " " << face + 1 << " " << face + 2 << " " << face + 6 << " " << face + 5 << " ";
                    escrever << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    //face 6
                    face += 8;
                }
            }
        }
    }

    //fechar o fluxo
    escrever.close();
}
