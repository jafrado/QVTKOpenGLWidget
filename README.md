# QVTKOpenGLWidget
Test app for verification of VTK built with support of QT+OpenGL

# Installation

Unix
VTK with QT5 and OpenGL
```
apt-get install vtk qt5 opengl
```

Windows
VTK with QT and OpenGL installed.
```
C:\vcpkg>vcpkg install qt5 vtk[opengl] --triplet x64-windows
```

# Build 

Unix
```
cd QVTKOpenGLWidget; mkdir build; cd !$ & cmake ..
```

Windows
Under Visual Studio 2019 (Community Edition) Developer Command Prompt
```
cd QVTKOpenGLWidget
cmake .. -DCMAKE_TOOLCHAIN_FILE=C:/vcpkg/scripts/buildsystems/vcpkg.cmake 
devenv /rebuild Release  qvtkopengl.sln
devenv /rebuild Debug qvtkopengl.sln
```

# Expected Results

The application will launch as below, you can use the mouse to move around the cylinder and zoom in and out with the Middle mouse wheel.

![alt text](https://github.com/jafrado/QVTKOpenGLWidget/raw/master/qvtkopenglwidget.jpg "QVTKOpenGLWidget Example")


