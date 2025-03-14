#include "rtweekend.h"

#include "camera.h"


int main() {



    hittable_list world;

    //MATERIALS 
    //materials are created by inputing Od color, Os color, Kd, Ks, Ka, Kgls

    //purple material
    std::shared_ptr<material> purple_material = std::make_shared<material>(
        color(1.0, 0.0, 1.0), color(1.0, 1.0, 1.0), 0.7, 0.2, 0.1, 16.0, 0.0);

    //white material
    std::shared_ptr<material> white_material = std::make_shared<material>(
        color(1.0, 1.0, 1.0), color(1.0, 1.0, 1.0), 0.8, 0.1, 0.3, 4.0, 0.0);

    //reflective material
    std::shared_ptr<material> reflective_material = std::make_shared<material>(
        color(0.75, 0.75, 0.75), color(1.0, 1.0, 1.0), 0.0, 0.1, 0.1, 10.0, 0.9);

    //red material
    std::shared_ptr<material> red_material = std::make_shared<material>(
        color(1.0, 0.0, 0.0), color(0.5, 1.0, 0.5), 0.8, 0.8, 0.1, 32.0, 0.0);

    //green material
    std::shared_ptr<material> green_material = std::make_shared<material>(
        color(0.0, 1.0, 0.0), color(0.5, 1.0, 0.5), 0.7, 0.5, 0.1, 64.0, 0.0);

    //blue material
    std::shared_ptr<material> blue_material = std::make_shared<material>(
        color(0.0, 0.0, 1.0), color(1.0, 1.0, 1.0), 0.9, 0.9, 0.1, 32.0, 0.0);

    //yellow material
    std::shared_ptr<material> yellow_material = std::make_shared<material>(
        color(1.0, 1.0, 0.0), color(1.0, 1.0, 1.0), 0.9, 0.5, 0.1, 4.0, 0.0);

    //SPHERES
    //spheres get added by inputing their center point, radius, and assigning them a material

    // world.add(std::make_shared<sphere>(point3(0.0, 0.0, 0.0), 0.4, purple_material));

    // world.add(std::make_shared<sphere>(point3(0.45, 0.0, -0.15), 0.15, white_material));

    // world.add(std::make_shared<sphere>(point3(0.0, 0.0, -0.1), 0.2, red_material));
    
    // world.add(std::make_shared<sphere>(point3(-0.6, 0.0, 0.0), 0.3, green_material));
    
    // world.add(std::make_shared<sphere>(point3(0.0, -10000.5, 0.0), 10000, blue_material));









    //base head
    // world.add(std::make_shared<sphere>(point3(0.0, -0.1, 0.0), 0.45, blue_material));

    // //ears
    // world.add(std::make_shared<sphere>(point3(-0.3, 0.3, 0.1), 0.3, blue_material));
    // world.add(std::make_shared<sphere>(point3(0.3, 0.3, 0.1), 0.3, blue_material));

    // //nose
    // world.add(std::make_shared<sphere>(point3(0.0, -0.1, 0.45), 0.05, red_material));

    // //eyes
    // world.add(std::make_shared<sphere>(point3(-0.15, 0.04, 0.45), 0.05, red_material));
    // world.add(std::make_shared<sphere>(point3(-0.15, 0.04, 0.475), 0.03, green_material));

    // world.add(std::make_shared<sphere>(point3(0.15, 0.04, 0.45), 0.05, red_material));
    // world.add(std::make_shared<sphere>(point3(0.15, 0.04, 0.475), 0.03, green_material));

    // //teeth
    // world.add(std::make_shared<sphere>(point3(0.0, -0.25, 0.4), 0.05, white_material));
    
    // world.add(std::make_shared<sphere>(point3(-0.05, -0.25, 0.4), 0.05, white_material));
    // world.add(std::make_shared<sphere>(point3(-0.1, -0.23, 0.39), 0.05, white_material));
    // world.add(std::make_shared<sphere>(point3(-0.15, -0.21, 0.38), 0.05, white_material));

    // world.add(std::make_shared<sphere>(point3(0.05, -0.25, 0.4), 0.05, white_material));
    // world.add(std::make_shared<sphere>(point3(0.1, -0.23, 0.39), 0.05, white_material));
    // world.add(std::make_shared<sphere>(point3(0.15, -0.21, 0.38), 0.05, white_material));






    // world.add(std::make_shared<sphere>(point3(0.0, 0.3, -1.0), 0.25, reflective_material));

    // //POLYGONS
    // std::vector<point3> triangle1 = {
    //     point3(0.0, -0.7, -0.5),
    //     point3(1.0, 0.4, -1.0),
    //     point3(0.0, -0.7, -1.5)
    // };
    // world.add(std::make_shared<polygon>(triangle1, blue_material));

    // std::vector<point3> triangle2 = {
    //     point3(0.0, -0.7, -0.5),
    //     point3(0.0, -0.7, -1.5),
    //     point3(-1.0, 0.4, -1.0)
    // };
    // world.add(std::make_shared<polygon>(triangle2, yellow_material));






    // world.add(std::make_shared<sphere>(point3(0.5, 0.0, -0.15), 0.05, white_material));
    // world.add(std::make_shared<sphere>(point3(0.3, 0.0, -0.1), 0.08, red_material));
    // world.add(std::make_shared<sphere>(point3(-0.6, 0.0, 0.0), 0.3, green_material));

    // world.add(std::make_shared<sphere>(point3(0.1, -0.55, 0.25), 0.3, reflective_material));


    // std::vector<point3> blue_triangle = {
    //     point3(0.3, -0.3, -0.4),
    //     point3(0.0, 0.3, -0.1),
    //     point3(-0.3, -0.3, 0.2)
    // };
    // world.add(std::make_shared<polygon>(blue_triangle, blue_material));


    // std::vector<point3> yellow_triangle = {
    //     point3(-0.2, 0.1, 0.1),
    //     point3(-0.2, -0.5, 0.2),
    //     point3(-0.2, 0.1, -0.3)
    // };
    // world.add(std::make_shared<polygon>(yellow_triangle, yellow_material));




    std::vector<point3> yellow_wall = {
            point3(-0.5, -0.5, -0.001),
            point3(0.5, -0.5, -0.001),
            point3(0.5, 0.5, -0.001),
            point3(-0.5, 0.5, -0.001)
        };
    world.add(std::make_shared<polygon>(yellow_wall, yellow_material));

    std::vector<point3> blue_wall = {
        point3(0.5, -0.5, 0.0),
        point3(0.5, 0.5, 0.0),
        point3(0.7, 0.5, 0.8),
        point3(0.7, -0.5, 0.8)
    };
    world.add(std::make_shared<polygon>(blue_wall, blue_material));

    std::vector<point3> red_wall = {
        point3(-0.5, -0.5, 0.0),
        point3(-0.5, 0.5, 0.0),
        point3(-0.7, 0.5, 0.8),
        point3(-0.7, -0.5, 0.8)
    };
    world.add(std::make_shared<polygon>(red_wall, red_material));


    


    std::vector<point3> purple_wall = {
        point3(-0.5, -0.5, 0.0),
        point3(0.5, -0.5, 0.0),
        point3(0.7, -0.5, 0.8),
        point3(-0.7, -0.5, 0.8)

    };
    world.add(std::make_shared<polygon>(purple_wall, purple_material));




    world.add(std::make_shared<sphere>(point3(0.2, 0.14, 0.5), 0.05, white_material));
    world.add(std::make_shared<sphere>(point3(0.0, -0.1, 0.5), 0.12, reflective_material));

    world.add(std::make_shared<sphere>(point3(-0.3, -0.2, 0.5), 0.07, red_material));
    world.add(std::make_shared<sphere>(point3(-0.2, -0.5, 0.2), 0.04, blue_material));
    world.add(std::make_shared<sphere>(point3(-0.3, 0.3, 0.1), 0.2, green_material));
    

    vec3 L_dir = unit_vector(vec3(0.0, 0.3, 0.8));
    camera cam;
    cam.aspect_ratio = 1;
    cam.image_width = 400;
    cam.render(world, L_dir);

}