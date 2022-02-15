#include "CutEllipsoid.h"
#include <iostream>
#include "sculptor.h"
#include "figurageometrica.h"
CutEllipsoid::CutEllipsoid(int xcenter,int ycenter,int zcenter ,int rx, int ry, int rz,float r,float g,float b,float a)
{
    this->xcenter=xcenter; this->ycenter=ycenter; this->rx=rx; this->ry=ry; this->rz=rz;
    this->zcenter=zcenter;this->g=g; this->b=b; this->r=r; this->a=a;
}

void CutEllipsoid::draw(Sculptor &s1){
s1.setColor(r,g,b,a);
s1.CutEllipsoid(xcenter,ycenter,zcenter,rx,ry,rz);
}
