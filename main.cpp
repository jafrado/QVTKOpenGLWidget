
#include "QVTKOpenGLWindow.h"

#include <QApplication>
#include <QSurfaceFormat>

#include <QVTKOpenGLWidget.h>

int main(int argc, char *argv[]) 
{

  QApplication app(argc, argv);

  QVTKOpenGLWindow window;
  window.show();

  return app.exec();
}