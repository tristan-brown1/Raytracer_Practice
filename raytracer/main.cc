#include "rtweekend.h"

#include "camera.h"
#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"




int main() {



    hittable_list world;

    //MATERIALS 
    //materials are created by inputing Od color, Os color, Kd, Ks, Ka, Kgls

    //purple material
    std::shared_ptr<material> purple_material = std::make_shared<material>(
        color(1.0, 0.0, 1.0), color(1.0, 1.0, 1.0), 0.7, 0.2, 0.1, 16.0
    );

    //white material
    std::shared_ptr<material> white_material = std::make_shared<material>(
        color(1.0, 1.0, 1.0), color(1.0, 1.0, 1.0), 0.8, 0.1, 0.3, 4.0
    );

    //red material
    std::shared_ptr<material> red_material = std::make_shared<material>(
        color(1.0, 0.0, 0.0), color(1.0, 1.0, 1.0), 0.6, 0.3, 0.1, 32.0
    );

    //green material
    std::shared_ptr<material> green_material = std::make_shared<material>(
        color(0.0, 1.0, 0.0), color(0.5, 1.0, 0.5), 0.7, 0.2, 0.1, 64.0
    );

    //blue material
    std::shared_ptr<material> blue_material = std::make_shared<material>(
        color(0.0, 0.0, 1.0), color(1.0, 1.0, 1.0), 0.9, 0.0, 0.1, 16.0
    );


    //SPHERES
    //spheres get added by inputing their center point, radius, and assigning them a material

    // world.add(std::make_shared<sphere>(point3(0.0, 0.0, 0.0), 0.4, purple_material));

    // world.add(std::make_shared<sphere>(point3(0.45, 0.0, -0.15), 0.15, white_material));

    // world.add(std::make_shared<sphere>(point3(0.0, 0.0, -0.1), 0.2, red_material));
    
    // world.add(std::make_shared<sphere>(point3(-0.6, 0.0, 0.0), 0.3, green_material));
    
    // world.add(std::make_shared<sphere>(point3(0.0, -10000.5, 0.0), 10000, blue_material));

    //base head
    world.add(std::make_shared<sphere>(point3(0.0, -0.1, 0.0), 0.45, blue_material));

    //ears
    world.add(std::make_shared<sphere>(point3(-0.3, 0.3, 0.1), 0.3, blue_material));
    world.add(std::make_shared<sphere>(point3(0.3, 0.3, 0.1), 0.3, blue_material));

    //nose
    world.add(std::make_shared<sphere>(point3(0.0, -0.1, 0.45), 0.05, red_material));

    //eyes
    world.add(std::make_shared<sphere>(point3(-0.15, 0.04, 0.45), 0.05, red_material));
    world.add(std::make_shared<sphere>(point3(-0.15, 0.04, 0.475), 0.03, green_material));

    world.add(std::make_shared<sphere>(point3(0.15, 0.04, 0.45), 0.05, red_material));
    world.add(std::make_shared<sphere>(point3(0.15, 0.04, 0.475), 0.03, green_material));

    //teeth
    world.add(std::make_shared<sphere>(point3(0.0, -0.25, 0.4), 0.05, white_material));
    
    world.add(std::make_shared<sphere>(point3(-0.05, -0.25, 0.4), 0.05, white_material));
    world.add(std::make_shared<sphere>(point3(-0.1, -0.23, 0.39), 0.05, white_material));
    world.add(std::make_shared<sphere>(point3(-0.15, -0.21, 0.38), 0.05, white_material));

    world.add(std::make_shared<sphere>(point3(0.05, -0.25, 0.4), 0.05, white_material));
    world.add(std::make_shared<sphere>(point3(0.1, -0.23, 0.39), 0.05, white_material));
    world.add(std::make_shared<sphere>(point3(0.15, -0.21, 0.38), 0.05, white_material));

    camera cam;
    cam.aspect_ratio = 1;
    cam.image_width = 400;
    cam.render(world);

}