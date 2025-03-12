#ifndef HITTABLE_H
#define HITTABLE_H

#include "rtweekend.h"

class hit_record {
    public:
        point3 p;
        vec3 normal;
        double t;
        bool front_face;
        bool is_in_shadow = false;
        std::shared_ptr<material> mat; 
        double u;
        double v;

        void set_face_normal(const ray& r, const vec3& outward_normal) {
            front_face = dot(r.direction(), outward_normal) < 0;
            normal = front_face ? outward_normal : -outward_normal;
        }

        void set_material(std::shared_ptr<material> new_mat) {
            mat = new_mat;
        }
};

class hittable {
    public:
        virtual ~hittable() = default;
        virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const = 0;

        bool is_in_shadow(const point3& point, const vec3& light_dir, const hittable& world) const {
            ray shadow_ray(point + 1e-4 * light_dir, light_dir);
            hit_record temp_rec;
            return world.hit(shadow_ray, interval(1e-4, 1e6), temp_rec);
        }
};

#endif
