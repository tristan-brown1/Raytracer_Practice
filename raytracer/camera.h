#ifndef CAMERA_H
#define CAMERA_H

//#include "hittable.h"
#include "rtweekend.h"

class camera {

    public:
        double aspect_ratio = 1.0;
        int image_width = 100;

        /* for some reason my output looks just a little 
            further away unless i change lookfrom to 0.5 in z*/
        point3 lookfrom = point3(0, 0, 1);


        point3 lookat = point3(0, 0, 0); 
        vec3 lookup = vec3(0, 1, 0); 

        void render(const hittable& world, const vec3& L_dir){
            initialize();

            std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

            for (int j = 0; j < image_height; j++){
                std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
                for (int i = 0; i < image_width; i++){

                    auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
                    auto ray_direction = pixel_center - lookfrom;
                    ray r(lookfrom, ray_direction);

                    color pixel_color = ray_color(r, world, L_dir, 5);

                    write_color(std::cout, pixel_color);
                }
            }
            std::clog << "\rDone.                   \n";
        }

        
    
    private:

        int image_height;
        point3 pixel00_loc;
        vec3 pixel_delta_u;
        vec3 pixel_delta_v;

        void initialize() {
            image_height = static_cast<int>(image_width / aspect_ratio);
            image_height = (image_height < 1) ? 1 : image_height;
    
            // camera coordinate system
            vec3 w = unit_vector(lookfrom - lookat);  
            vec3 u = unit_vector(cross(lookup, w));   
            vec3 v = cross(w, u);                     
    
            // set up the viewport
            double fov = 90.0;
            double theta = degrees_to_radians(fov);
            double viewport_height = 2.0 * tan(theta / 2);
            double viewport_width = viewport_height * (static_cast<double>(image_width) / image_height);
    
            vec3 viewport_u = viewport_width * u;
            vec3 viewport_v = viewport_height * -v;  
    
            pixel_delta_u = viewport_u / image_width;
            pixel_delta_v = viewport_v / image_height;
    
            vec3 viewport_upper_left = lookfrom - (w * 1) - viewport_u / 2 - viewport_v / 2;
            pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);
        }

        
    
        color ray_color(const ray& r, const hittable& world, const vec3& L_dir, int depth){
            hit_record rec;
        
            if(depth <= 0){
                return color(0,0,0);
            }


            if (world.hit(r, interval(0, infinity), rec)) {

                

                vec3 N = unit_vector(rec.normal);        // surface normal at the hit
                //vec3 L_dir = unit_vector(vec3(1, 1, 1)); // light direction
                vec3 L = vec3(1, 1, 1);                  // light color
                vec3 V = unit_vector(-r.direction());    // view direction
        
                color Od = rec.mat->Od;
                color Os = rec.mat->Os;
                double Kd = rec.mat->Kd;
                double Ks = rec.mat->Ks;
                double Ka = rec.mat->Ka;
                double Kgls = rec.mat->Kgls;
                double refl = rec.mat->refl;

                // ambient component
                color I_a = color(0.1, 0.1, 0.1) * Ka * Od;

                color I_d = color(0, 0, 0);
                color I_s = color(0, 0, 0);

                
        
                if(!world.is_in_shadow(rec.p, L_dir, world)){

                    // diffuse component
                    double diff_intensity = std::max(0.0, dot(N, L_dir));
                    I_d = Kd * L * Od * diff_intensity;
            
                    // specular component
                    vec3 R = reflect(-L_dir, N);
                    double spec_intensity = pow(std::max(0.0, dot(R, V)), Kgls);
                    I_s = Ks * L * Os * spec_intensity;
                
                }



                color reflected_color = color(0,0,0);
                if(refl > 0){
                    vec3 reflect_dir = reflect(r.direction(), N); 
                    ray reflected_ray(rec.p + 0.001 * reflect_dir, reflect_dir);
                    reflected_color = refl * ray_color(reflected_ray, world, L_dir, depth - 1);

                }
                
        
                // final color = ambient + diffuse + specular
                return I_a + I_d + I_s + reflected_color;
            }
        
            // background color

            //special sky gradiant that looks nice 
            vec3 unit_direction = unit_vector(r.direction());
            auto a = 0.5 * (unit_direction.y() + 1.0);
            return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);

            //testcase grey
            //return color(0.2, 0.2, 0.2);
        }
        
        

};

#endif