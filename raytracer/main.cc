#include "rtweekend.h"

#include "camera.h"
#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"




int main() {



    hittable_list world;

    //SPHERES
    //spheres set by first giving center point and then radius

    //small spheres
    world.add(make_shared<sphere>(point3(0,0,0), .4));
    // world.add(make_shared<sphere>(point3(-1,0,-1.5), 0.5));
    // world.add(make_shared<sphere>(point3(2,0,-3), 0.5));

    //big sphere 
    // world.add(make_shared<sphere>(point3(0,-100.5,-1), 100));

    
    camera cam;
    cam.aspect_ratio = 1;
    cam.image_width = 400;
    cam.render(world);

}