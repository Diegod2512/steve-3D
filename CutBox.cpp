#include "CutBox.h"
#include <iostream>
#include "sculptor.h"
#include "figurageometrica.h"

CutBox::CutBox(int x0, int x1, int y0, int y1, int z0, int z1,float r,float g,float b,float a)
{
    this->x0=x0; this->x1=x1; this->y0=y0; this->y1=y1; this->z0=z0 ;
    this->z1=z1;this->g=g; this->b=b; this->r=r; this->a=a;
}

void CutBox::draw(Sculptor &s){
s.setColor(r,g,b,a);
s.CutBox(x0,x1,y0,y1,z0,z1);
}
