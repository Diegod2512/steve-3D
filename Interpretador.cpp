#include "Interpretador.h"
#include "figurageometrica.h"
#include "putvoxel.h"
#include "cutvoxel.h"
#include "putbox.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

Interpretador::Interpretador(){

}
std::vector<FiguraGeometrica*> Interpretador::parse(std::string endereco_arquivo){
std::vector<FiguraGeometrica*> figs;

    std::ifstream fin;
    std::string s, token;
    std::stringstream ss;


    fin.open(file_name.c_str());

    while(fin.good()){
        std::getline(fin,s);
        if(fin.good()){
            ss.clear();
            ss.str(s);
            ss >> token;
            if(ss.good()){
                if (token.compare("dim") == 0){
                        int x,y,z;
                    ss >> x >> y >> z;
                }
                else if(token.compare("putvoxel")==0){
                    int x,y,z;
                    float r,g,b,a;
                    ss >> x >> y >> z >> r >> g >> b >> a;
                    figs.push_back(new PutVoxel(x, y, z, r, g, b, a));
                }
                else if(token.compare("cutvoxel")==0){
                    int x,y,z;
                    ss >> x >> y >> z;
                    figs.push_back(new cutVoxel(x, y, z));
                }
                else if(token.compare("putbox")==0){
                    int x0, x1, y0, y1, z0, z1;
                    float r, g, b, a;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
                    figs.push_back(new putBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
                }
                else if(token.compare("cutbox")==0){
                    int x0, x1, y0, y1, z0, z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
                    figs.push_back(new cutBox(x0, x1, y0, y1, z0, z1));
                }
                else if(token.compare("putsphere")==0){
                    int xcenter, ycenter, zcenter, radius;
                    float r, g, b, a;
                    ss >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> a;
                    figs.push_back(new putSphere(xcenter, ycenter, zcenter, radius, r, g, b, a));
                }
                else if(token.compare("cutsphere")==0){
                    int xcenter, ycenter, zcenter, radius;
                    ss >> xcenter >> ycenter >> zcenter >> radius;
                    figs.push_back(new cutSphere(xcenter, ycenter, zcenter, radius));
                }
                else if(token.compare("putellipsoid")==0){
                    int xcenter, rx, ycenter, ry, zcenter, rz;
                    float r, g, b, a;
                    ss >> xcenter >> rx >> ycenter >> ry >> zcenter >> rz >> r >> g >> b >> a;
                    figs.push_back(new putEllipsoid(xcenter, rx, ycenter, ry, zcenter, rz, r, g, b, a));
                }
                else if(token.compare("cutellipsoid")==0){
                    int xcenter, rx, ycenter, ry, zcenter, rz;
                    ss >> xcenter >> rx >> ycenter >> ry >> zcenter >> rz;
                    figs.push_back(new cutEllipsoid(xcenter, rx, ycenter, ry, zcenter, rz));
                }
            }
        }
    }
    return (figs);
};

int Interpretador::getDimX(){
    return x;
};

int Interpretador::getDimY(){
    return y;
};

int Interpretador::getDimZ(){
    return z;
    
