#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//Qt
#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QWidget>
#include <QGroupBox>
#include <QScrollArea>

//PCL
#include <pcl/io/ply_io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/obj_io.h>
#include <pcl/io/vtk_lib_io.h>
#include <pcl/io/io.h>
#include <pcl/surface/vtk_smoothing/vtk_utils.h>

//VTK
#include <QVTKWidget.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderer.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud;
    pcl::PolygonMesh::Ptr poly_mesh;

private slots:
    void on_actionOpen_file_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
