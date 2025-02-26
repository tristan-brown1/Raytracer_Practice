#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "material.h"

class sphere : public hittable {
    public:

        sphere(point3 cen, double r, std::shared_ptr<material> m)
            : center(cen), radius(r), mat(m) {}

            bool hit(const ray& r, interval ray_t, hit_record& rec) const override{
                vec3 oc = center - r.origin();
                auto a = r.direction().length_squared();
                auto h = dot(r.direction(), oc);
                auto c = oc.length_squared() - radius*radius;
    
                auto discriminant = h*h - a*c;
    
                if(discriminant < 0) 
                    return false;
                auto sqrtd = std::sqrt(discriminant);
    
                auto root = (h - sqrtd) / a;
                if(!ray_t.surrounds(root)) {
                    root = (h + sqrtd) / a;
                    if (!ray_t.surrounds(root))
                        return false;
                }

            rec.t = root;
            rec.p = r.at(rec.t);
            rec.set_face_normal(r, (rec.p - center) / radius);
            rec.set_material(mat);

            return true;
        }

        private:
            point3 center;
            double radius;
            std::shared_ptr<material> mat;
};

#endif

