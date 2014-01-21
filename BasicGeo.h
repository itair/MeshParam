#ifndef MASHPARAM_BASICGOE_H
#define  MASHPARAM_BASICGOE_H

const double kInitDouble = 0.0; 
const int kInitIndex = 0;

class Point {
public:
    double x;
    double y;
    double z;
    Point() { x = y = z = kInitDouble; }    
    void set(double dx,double dy,double dz)  { 
        x=dx;    y=dy;    z=dx; 
    } 
    void set(Point &p)   { 
        x=p.x;   y=p.y;   z=p.z; 
    } 
    Point(double xx,double yy,double zz)   { 
        x=xx;   y=yy;     z=zz; 
    }
};

class Verctor3D {
public:
    double x;
    double y;
    double z;
    Verctor3D () { x = y = z = kInitDouble; }
    void set(double dx,double dy,double dz)  { 
        x=dx;    y=dy;    z=dx; 
    } 
    void set(Verctor3D &p)   { 
        x=p.x;   y=p.y;   z=p.z; 
    } 
    Verctor3D(double xx,double yy,double zz)   { 
        x=xx;   y=yy;     z=zz; 
    }    
    
};

class Face {
public:
    int v0;
    int v1;
    int v2;
    Verctor3D normal;
    double  area;

    Face() { v0 = v1 = v2 = kInitIndex; area = kInitDouble; }
    void set(int dx, int dy, int dz)  { 
        v0=dx;    v1=dy;    v2=dx; 
    } 
    void set(Face &p)   { 
        v0=p.v0;   v1 =p.v1;   v2 =p.v2; 
    } 
    Face(int xx, int yy, int zz)   { 
        v0=xx;   v1=yy;     v2=zz; 
    }
    
        
};
class Line {
public:
    Line() { v0 = v1 = kInitIndex; length = kInitDouble; }

    int v0;
    int v1;
    double length;
};


#endif  //MASHPARAM_BASICGOE_H