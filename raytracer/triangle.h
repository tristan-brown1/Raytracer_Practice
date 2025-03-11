#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "hittable.h"
#include "material.h"

class triangle : public hittable {
    public:
        triangle(const point3& Q, const vec3& u, const vec3& v, std::shared_ptr<material> m)
            : Q(Q), u(u), v(v), mat(m) {}
        
    private:
        point3 Q;
        vec3 u, v;
        shared_ptr<material> mat;

};

#endif