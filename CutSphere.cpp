#include "CutSphere.h"
#include <iostream>
#include "sculptor.h"
#include "figurageometrica.h"
CutSphere::CutSphere(int xcenter,int ycenter,int zcenter,float r,float g,float b,float a)
{
    this->xcenter=xcenter; this->ycenter=ycenter;
    this->zcenter=zcenter;this->g=g; this->b=b; this->r=r; this->a=a;
}

void CutSphere::draw(Sculptor &s1){
s1.setColor(r,g,b,a);
s1.CutSphere(xcenter,ycenter,zcenter);
}
