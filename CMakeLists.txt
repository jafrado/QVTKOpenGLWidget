cmake_minimum_required(VERSION 3.5)
project(qvtkopengl)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# init_qt: Let's do the CMake job for us
set(CMAKE_AUTOMOC ON) # For meta object compiler
set(CMAKE_AUTORCC ON) # Resource files
set(CMAKE_AUTOUIC ON) # UI files

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Find the QtWidgets library
find_package(Qt5 CONFIG REQUIRED Widgets)
find_package(VTK CONFIG REQUIRED)

# Example app
add_executable(${PROJECT_NAME} main.cpp QVTKOpenGLWindow.cpp)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets vtkCommonCore vtkFiltersSources vtkGUISupportQt vtkInteractionStyle vtkRenderingCore vtkRenderingOpenGL2)
qt5_use_modules(${PROJECT_NAME} Widgets)
