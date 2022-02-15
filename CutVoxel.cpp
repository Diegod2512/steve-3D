#include "CutVoxel.h"
#include<iostream>
#include "sculptor.h"
#include "figurageometrica.h"
CutVoxel::CutVoxel(int x,y,z,float r, g,b,alpha)
{
    this->x=x; this->y=y;
    this->z=z;this->g=g; this->b=b; this->r=r; this->a=a;
}

void Cutvoxel::draw(Sculptor &s){
s.setColor(this->r,this->g,this->b,this->a)
s.CutVoxel(this->x,this->y,this->z);
}
