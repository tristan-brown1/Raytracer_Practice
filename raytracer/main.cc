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
    //world.add(make_shared<sphere>(point3(0,0,0), 0.4));

    world.add(make_shared<sphere>( point3(0.45, 0.0, -0.15), 0.15));
    world.add(make_shared<sphere>(point3(0.0, 0.0, -0.1), 0.2)); 
    world.add(make_shared<sphere>(point3(-0.6, 0.0, 0.0), 0.3)); 

    //big sphere 
    // world.add(make_shared<sphere>(point3(0,-100.5,-1), 100));

    world.add(make_shared<sphere>(point3(0,-10000.5,0), 10000.0));
    

    camera cam;
    cam.aspect_ratio = 1;
    cam.image_width = 400;
    cam.render(world);

}