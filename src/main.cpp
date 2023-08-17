#include <iostream>

#include "app/viewer.h"
#include "app/viewer_ui.h"
#include "app/viewer_window.h"

#include "math/vec.h"
#include "math/matrix.h"
#include <cassert>

const size_t WIDTH = 1000;
const size_t HEIGHT = 800;


/*bool validateMatrices(math::Mat4& myMat, glm::mat4& glmMat) {
    float diff = 0.0;
    float* l = myMat.getRawData();
    float* r = glm::value_ptr(glmMat);
    
    for (int i = 0; i < 16; i++) {
        std::cout << l[i] << " vs " << r[i] << std::endl;
        if ((i+1) % 4 == 0) std::cout << "\n";
        diff += fabs(l[i] - r[i]);
    }
    
    if (diff < math::NEARLY_ZERO) return true;
    return false;
}*/

int main() {

    /*math::Vec3 l{1, 0, 0};
    math::Vec3 r{0, 1, 0};
    math::Vec3 o{0, 0, 1};

    assert(l.cross(r) == o);
    assert(r.cross(o) == l);
    assert(o.cross(l) == r);
    
    
    math::Mat4 m0{};
    glm::mat4 m1{1.0};


    if (!validateMatrices(m0, m1)) {
        std::cout << "Identities didn't match!\n";
    }

    m0 = math::Mat4::fromTranslation(math::Vec3{1, 2, 3});
    m1 = glm::translate(glm::mat4(1.0),glm::vec3(1, 2, 3));

    if (!validateMatrices(m0, m1)) {
        std::cout << "Translate didn't match!\n";
        return -1;
    }

    m0 = math::Mat4::orthographicProjection(-10., 10., -10., 10., .1, 1000.);
    m1 = glm::ortho(-10., 10., -10., 10., .1, 1000.);

    if (!validateMatrices(m0, m1)) {
        std::cout << "Ortho didn't match!\n";
        return -1;
    }

 
    m0 = math::Mat4::perspectiveProjection(glm::radians(45.0), 800.0 / 600.0, 0.1, 1000.0);
    m1 = glm::perspective(glm::radians(45.0), 800.0 / 600.0, 0.1, 1000.);

 

    if (!validateMatrices(m0, m1)) {
        std::cout << "Persp didn't match!\n";
        return -1;
    }

  

    m0 = math::Mat4::lookAt(math::Vec3{1,2,3}, math::Vec3{ 1,1,1 }, math::Vec3{ 0.0,1.0,0.0 });
    m1 = glm::lookAt(glm::vec3(1,2,3),glm::vec3(1,1,1),glm::vec3(0,1.0,0.0));

    std::cout << m0 << std::endl;
    std::cout << glm::to_string(m1) << std::endl;

    if (!validateMatrices(m0, m1)) {
        std::cout << "Look at didn't match!\n";
        return -1;
    }


    std::cout << "Done!\n";
    //return 0;
    */


    //First create an app
    Viewer app{};

    //Create a window for rendering the app
    ViewerWindow window{ app,WIDTH,HEIGHT};

    //Init the app with graphics resources
    app.init();

    //Create a ui if you want it, might need access to app state if its a custom ui
    //Ui object by default displays imgui's demo window
    ViewerUi ui{window,app};


    while (!window.closed()) {


        //Check for any input events
        window.pollEvents();

        //Start new ui frame
        ui.newFrame();

        //Update window
        window.update(app);

        //Update app state 
        app.update();
        //Render app state
        app.render();

     
        //Update ui state
        ui.update();
        //Render ui state
        ui.render();

        //Swap back-buffer to screen
        window.swapBuffers();
    }

   ui.shutdown();

    return 0;
}

