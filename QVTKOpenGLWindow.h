
#ifndef _VTK_QVTKOPENGL_MAINWINDOW_H
#define _VTK_QVTKOPENGL_MAINWINDOW_H


// Visualization Toolkit (VTK)
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRendererCollection.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkCylinderSource.h>
#include <vtkRegularPolygonSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkSmartPointer.h>
#include <vtkMapper.h>
#include <vtkActor.h>
#include <QVTKOpenGLWidget.h>
#include <QVTKWidget.h>
#include <QVTKInteractorAdapter.h>

// Qt Library
#include <QWidget>
#include <QSemaphore>
#include <QSurfaceFormat>
#include <QDebug>
#include <QWidget>
#include <QSemaphore>
#include <QMainWindow>
#include <QLabel>

class QVTKOpenGLWindow :  public QVTKOpenGLWidget
{
    Q_OBJECT
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> renderWindow;

public:
    explicit QVTKOpenGLWindow(QWidget *parent = 0);
};

#endif //!_VTK_QVTKOPENGL_MAINWINDOW_H
