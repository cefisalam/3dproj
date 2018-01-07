#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//Internal
#include "point2mesh.h"
#include "k2class.h"

//Qt
#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include <QWidget>
#include <QGroupBox>
#include <QScrollArea>
#include <QToolButton>
#include <QElapsedTimer>
#include <QDoubleSpinBox>
#include <QComboBox>
#include <QStringList>

//PCL
#include <pcl/io/ply_io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/obj_io.h>
#include <pcl/io/vtk_lib_io.h>
#include <pcl/io/io.h>
#include <pcl/surface/vtk_smoothing/vtk_utils.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>

//VTK
#include <QVTKWidget.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkAutoInit.h>

VTK_MODULE_INIT(vtkRenderingOpenGL2)
VTK_MODULE_INIT(vtkInteractionStyle)
VTK_MODULE_INIT(vtkRenderingFreeType)

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;
    std::vector<pcl::PointCloud<pcl::PointXYZ>::Ptr> clouds_vec;
    pcl::PolygonMesh::Ptr poly_mesh;
    Point2Mesh p2m;
    bool flag;

public slots:
    void load_pcd_files(QStringList files_pcd);

private slots:
    void on_actionOpen_file_triggered();
    void on_actionSave_file_triggered();
    void on_toolButton_clicked();
    void on_toolButton_2_clicked();
    void on_toolButton_3_clicked();
    void on_actionOpen_files_triggered();
    void on_toolButton_4_clicked();

private:
    Ui::MainWindow *ui;
    QVTKWidget *widget1, *widget2;
    int flag_type = -1;
    QToolButton *toolButton;
    QDoubleSpinBox *z_axis_min, *z_axis_max;
    QComboBox *tri_comboBox;
    QSpinBox *poisonSpinBox;

protected:
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer1;
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
};

#endif // MAINWINDOW_H
