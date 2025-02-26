#ifndef MATERIAL_H
#define MATERIAL_H

#include "vec3.h"

class material {
    public:
        color Od;  // diffuse color
        color Os;  // specular color
        double Kd; // diffuse coefficient
        double Ks; // specular coefficient
        double Ka; // ambient coefficient
        double Kgls; // phong exponent
        
        material(const color& Od_, const color& Os_, double Kd_, double Ks_, double Ka_, double Kgls_)
            : Od(Od_), Os(Os_), Kd(Kd_), Ks(Ks_), Ka(Ka_), Kgls(Kgls_) {}
};


#endif
