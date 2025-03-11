#ifndef QUAD_H
#define QUAD_H

#include "hittable.h"
#include "material.h"

class quad : public hittable {
    public:
        quad(const point3& Q, const vec3& u, const vec3& v, std::shared_ptr<material> m)
            : Q(Q), u(u), v(v), mat(m)
        {
            //set_bounding_box();
            auto n = cross(u, v);
            normal = unit_vector(n);
            D = dot(normal, Q);
            w = n / dot(n,n);

            


        }
        // virtual void set_bounding_box(){
        //     auto bbox_diagonal = 
        // }


        bool hit(const ray& r, interval ray_t, hit_record& rec) const override{

            auto denom = dot(normal, r.direction());

            if(std::fabs(denom) < 1e-8){
                return false;
            }


            auto t = (D - dot(normal, r.origin())) / denom;

            if(!ray_t.contains(t)){
                return false;
            }

            if (!ray_t.contains(t)) {
                std::cout << "Quad missed: t=" << t << " not in " << ray_t.min << " to " << ray_t.max << "\n";
            }
            

            auto intersection = r.at(t);
            vec3 planar_hitpt_vector = intersection - Q;
            auto alpha = dot(w, cross(planar_hitpt_vector, v));
            auto beta = dot(w, cross(u, planar_hitpt_vector));

            if(!is_interior(alpha, beta, rec)){
                return false;
            }

            if (!is_interior(alpha, beta, rec)) {
                std::cout << "Hit outside quad: alpha=" << alpha << ", beta=" << beta << "\n";
            }
            


            rec.t = t;
            rec.p = intersection;
            rec.set_face_normal(r, normal);
            //rec.set_face_normal(r, dot(r.direction(), normal) < 0 ? normal : -normal);



            return true;
        }

        virtual bool is_interior(double a, double b, hit_record& rec) const{

            interval unit_interval = interval(0, 1);

            if( !unit_interval.contains(a) || !unit_interval.contains(b)){
                return false;
            }


            rec.u = a;
            rec.v = b;

            return true;
        }



    private:
        point3 Q;
        vec3 u, v;
        vec3 w;
        shared_ptr<material> mat;
        vec3 normal;
        double D;

};

#endif