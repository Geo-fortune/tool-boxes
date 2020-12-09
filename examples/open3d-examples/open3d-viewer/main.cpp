

// STL
#include <string>
#include <iostream>
#include <vector>
#include <memory>

#include "open3d/Open3D.h"
#include "MyGuiVisualizer.h"
#include "open3d/visualization/gui/Native.h"

#define WIDTH 1280
#define HEIGHT 960

int main(int argc, const char *argv[]){

    auto &app = open3d::visualization::gui::Application::GetInstance();
    app.Initialize(argc, argv);

    auto vis = std::make_shared<open3d::visualization::GuiVisualizer>("Open3D", WIDTH, HEIGHT);

    open3d::visualization::gui::Application::GetInstance().AddWindow(vis);
    vis.reset();

    app.Run();

    return EXIT_SUCCESS;
}
