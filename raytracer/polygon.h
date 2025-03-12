#ifndef POLYGON_H
#define POLYGON_H


#include "hittable.h"
#include <vector>

class polygon : public hittable {


    public:
        std::vector<point3> vertices;
        vec3 normal;
        std::shared_ptr<material> mat;
        double D;



        polygon(const std::vector<point3>& verts, std::shared_ptr<material> m)
            : vertices(verts), mat(m) {

                vec3 edge1 = vertices[1] - vertices[0];
                vec3 edge2 = vertices[2] - vertices[0];
                normal = unit_vector(cross(edge1, edge2));
                D = dot(normal, vertices[0]);
            }

        bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
            double denominator = dot(normal, r.direction());

            if (fabs(denominator) < 1e-8){
                return false;
            }

            double t = (D - dot(normal, r.origin())) / denominator;
            if(!ray_t.contains(t)){
                return false;
            }

            point3 P = r.at(t);

            if(!is_inside(P)){
                return false;
            }

            rec.t = t;
            rec.p = P;
            rec.set_face_normal(r, normal);
            rec.mat = mat;

            return true;

        }

    private:
        bool is_inside(const point3 P) const{
            int n = vertices.size();
            double total_angle = 0.0;

            for (int i = 0; i < n; i++){
                vec3 v1 = unit_vector(vertices[i] - P);
                vec3 v2 = unit_vector(vertices[(i + 1) % n] - P);
                double angle = acos(dot(v1, v2));
                total_angle += angle;
            }
            return fabs(total_angle - 2 * pi ) < 1e-4;
        }





};







#endif 