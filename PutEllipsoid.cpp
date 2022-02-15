#include "PutEllipsoid.h"
#include <iostream>
#include "sculptor.h"
#include "figurageometrica.h"
PutSphere::PutSphere(int xcenter,ycenter, zcenter ,int rx, int ry, int rz,float r,float g,float b,float a)
{
    this->xcenter=xcenter; this->ycenter=ycenter; this->rx=rx; this->ry=ry; this->rz=rz;
    this->zcenter=zcenter;this->g=g; this->b=b; this->r=r; this->a=a;
}

void PutSphere::draw(Sculptor &s1){
s.setColor(r,g,b,a)
s.PutSphere(xcenter,ycenter,zcenter,rx,ry,rz);
}
