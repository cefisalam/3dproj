#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    cloud (new pcl::PointCloud<pcl::PointXYZRGBA>()),
    poly_mesh (new pcl::PolygonMesh())
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_file_triggered()
{
    QString file_path = QFileDialog::getOpenFileName(this, tr("Open mesh file"),
                                                     "C:/",
                                                     tr("Meshes *.ply *.obj *.off *.vtk"));


    if (QString(".pcd").compare(file_path.mid(-1,4), Qt::CaseInsensitive) == 0)
    {
        pcl::io::loadPCDFile(file_path.toStdString(), *cloud);
    }

    else if (QString(".ply").compare(file_path.mid(-1,4), Qt::CaseInsensitive) == 0)
    {
        pcl::io::loadPLYFile(file_path.toStdString(), *poly_mesh);
    }

    else if (QString(".obj").compare(file_path.mid(-1,4), Qt::CaseInsensitive) == 0)
    {
        pcl::io::loadOBJFile(file_path.toStdString(), *poly_mesh);
    }

    else if (QString(".vtk").compare(file_path.mid(-1,4), Qt::CaseInsensitive) == 0)
    {
        pcl::io::loadPolygonFileVTK(file_path.toStdString(), *poly_mesh);
    }
}
