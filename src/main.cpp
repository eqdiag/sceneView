#include "core/app.h"
#include "core/window.h"
#include "core/ui.h"

const size_t WIDTH = 1000;
const size_t HEIGHT = 800;


int main() {
    

    //First create an app
    core::App app{};

    //Create a window for rendering the app
    core::Window window{ app ,WIDTH,HEIGHT,"customApp"};

    //Init the app with graphics resources
    app.init();

    //Create a ui if you want it, might need access to app state if its a custom ui
    //Ui object by default displays imgui's demo window
    core::Ui ui{window};


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

