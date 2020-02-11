
#include "QVTKOpenGLWindow.h"

#ifdef _MSC_VER
/* The below is MANDATORY for Windows builds or you will take an exception in vtkRenderer::SetRenderWindow(vtkRenderWindow *renwin) */
#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2); /* VTK was built with vtkRenderingOpenGL2 */
VTK_MODULE_INIT(vtkInteractionStyle);

#endif


QVTKOpenGLWindow::QVTKOpenGLWindow(QWidget *parent) 
    : QVTKOpenGLWidget(parent)
{

    // Set up the QVTK window
    auto renderer = vtkSmartPointer<vtkRenderer>::New();
    auto window = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
    this->SetRenderWindow(window.Get());
    window->AddRenderer(renderer);

    QSurfaceFormat surfaceFormat = QSurfaceFormat();
    surfaceFormat.setSamples(4);
    setFormat(surfaceFormat);
        
	this->setEnableHiDPI(true);

    vtkSmartPointer<vtkRegularPolygonSource> poly = vtkSmartPointer<vtkRegularPolygonSource>::New();
    poly->GeneratePolygonOff(); //gen only outline
    poly->SetNumberOfSides(50);
    poly->SetRadius(1 * 10);
    poly->SetCenter(0, 0, 0);
    poly->SetNormal(0, 1, 0);


    auto cylinderSource = vtkSmartPointer<vtkCylinderSource>::New();
    cylinderSource->SetCenter(0.0, 0.0, 0.0);
    cylinderSource->SetRadius(5.0);
    cylinderSource->SetHeight(7.0);
    cylinderSource->SetResolution(100);

    //setup actor/mapper for circle
    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(poly->GetOutputPort());
    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);
    renderer->AddActor(actor);

    mapper->SetInputConnection(cylinderSource->GetOutputPort());
    actor->SetMapper(mapper);
    renderer->AddActor(actor);

    this->update();
    
    window->Render();

}
