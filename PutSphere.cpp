#include "PutSphere.h"
#include <iostream>
#include "sculptor.h"
#include "figurageometrica.h"
PutSphere::PutSphere(int xcenter,ycenter,zcenter,float r,g,b, alpha)
{
    this->xcenter=xcenter; this->ycenter=ycenter;
    this->zcenter=zcenter;this->g=g; this->b=b; this->r=r; this->alpha=alpha;
}

void PutSphere::draw(Sculptor &s1){
s1.setColor(mr,mg,mb,alpha)
s1.PutSphere(xcenter,ycenter,zcenter);
