#include "mainwindow.h"
#include "ui_mainwindow.h"

//Constructor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    clouds_vec (0),
    cloud (new pcl::PointCloud<pcl::PointXYZ>()),
    p2m (nullptr),
    flag(false),
    poly_mesh (new pcl::PolygonMesh)
{
    ui->setupUi(this);
    this->setWindowTitle("3D-V2 Scanner");
    viewer.reset (new pcl::visualization::PCLVisualizer ("viewer", false));
    viewer2.reset (new pcl::visualization::PCLVisualizer ("viewer2", false));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Function to load all kinds of point clouds/mesh (ply, vtk, obj, pcd)
void MainWindow::on_actionOpen_file_triggered()
{
    QString file_path = QFileDialog::getOpenFileName(this, tr("Open mesh file"),
                                                     "C:/",
                                                     tr("Meshes *.ply *.obj *.vtk *.pcd *.stl"));

    if (QString(".pcd").compare(file_path.mid(file_path.size()-4,4), Qt::CaseInsensitive) == 0)
    {
        pcl::PCLPointCloud2 cloud_blob;
        if (pcl::io::loadPCDFile(file_path.toStdString(), cloud_blob) != -1)
        {
            pcl::fromPCLPointCloud2 (cloud_blob, *cloud);
            ui->widget1->SetRenderWindow (viewer->getRenderWindow());
            viewer->setupInteractor (ui->widget1->GetInteractor(), ui->widget1->GetRenderWindow());

            if (viewer->addPointCloud (cloud, "cloud"))
            {
                ui->widget1->update();
                flag_type = 0;
            }
        }
    }

    else if (QString(".ply").compare(file_path.mid(file_path.size()-4,4), Qt::CaseInsensitive) == 0)
    {
        if (pcl::io::loadPLYFile(file_path.toStdString(), *poly_mesh) != -1)
        {
            ui->widget1->SetRenderWindow (viewer->getRenderWindow());
            viewer->setupInteractor (ui->widget1->GetInteractor(), ui->widget1->GetRenderWindow());
            viewer->initCameraParameters();

            if (viewer->addPolygonMesh(*poly_mesh, "meshes"))
            {
                ui->widget1->update();
                flag_type = 1;
            }
        }
    }

    else if (QString(".obj").compare(file_path.mid(file_path.size()-4,4), Qt::CaseInsensitive) == 0)
    {
        if (pcl::io::loadPolygonFileOBJ(file_path.toStdString(), *poly_mesh) != -1)
        {
            ui->widget1->SetRenderWindow (viewer->getRenderWindow());
            viewer->setupInteractor (ui->widget1->GetInteractor(), ui->widget1->GetRenderWindow());
            viewer->initCameraParameters();

            if (viewer->addPolygonMesh(*poly_mesh, "meshes"))
            {
                ui->widget1->update();
                flag_type = 2;
            }
        }
    }

    else if (QString(".vtk").compare(file_path.mid(file_path.size()-4,4), Qt::CaseInsensitive) == 0)
    {
        if (pcl::io::loadPolygonFileVTK(file_path.toStdString(), *poly_mesh) != -1)
        {
            ui->widget1->SetRenderWindow (viewer->getRenderWindow());
            viewer->setupInteractor (ui->widget1->GetInteractor(), ui->widget1->GetRenderWindow());
            viewer->initCameraParameters();

            if (viewer->addPolygonMesh(*poly_mesh, "meshes"))
            {
                ui->widget1->update();
                flag_type = 3;
            }
        }
    }

    else if (QString(".stl").compare(file_path.mid(file_path.size()-4,4), Qt::CaseInsensitive) == 0)
    {
        if (pcl::io::loadPolygonFileSTL(file_path.toStdString(), *poly_mesh) != -1)
        {
            ui->widget1->SetRenderWindow (viewer->getRenderWindow());
            viewer->setupInteractor (ui->widget1->GetInteractor(), ui->widget1->GetRenderWindow());
            viewer->initCameraParameters();

            if (viewer->addPolygonMesh(*poly_mesh, "meshes"))
            {
                ui->widget1->update();
                flag_type = 1;
            }
        }
    }
}

void MainWindow::on_actionSave_file_triggered()
{
    if (flag_type == -1)
    {
        QMessageBox msg;
        msg.setInformativeText("None file to be save");
        msg.exec();
    }

    else if (flag_type == 0)
    {
        QString file_name = QFileDialog::getSaveFileName(this, tr("Save file"), "",
                                                         tr("PCD (*.pcd)"));
        pcl::io::savePCDFileASCII (file_name.toStdString(), *cloud);
    }

    else if (flag_type == 1)
    {
        QString file_name = QFileDialog::getSaveFileName(this, tr("Save file"), "",
                                                         tr("PLY (*.ply)"));
        pcl::io::savePolygonFilePLY(file_name.toStdString(), *poly_mesh);
    }

    else if (flag_type == 2)
    {
        QString file_name = QFileDialog::getSaveFileName(this, tr("Save file"), "",
                                                         tr("OBJ (*.obj)"));
        pcl::io::saveOBJFile(file_name.toStdString(), *poly_mesh);
    }

    else if (flag_type == 3)
    {
        QString file_name = QFileDialog::getSaveFileName(this, tr("Save file"), "",
                                                         tr("VTK (*.vtk)"));
        pcl::io::savePolygonFileVTK(file_name.toStdString(), *poly_mesh);
    }
}

void MainWindow::create_k2_visualizer()
{
    kinect = new k1class();
    ui->widget1->SetRenderWindow (viewer->getRenderWindow());
    viewer->setCameraPosition( 0.0, 0.0, -2.5, 0.0, 0.0, 0.0 );
    viewer->setupInteractor (ui->widget1->GetInteractor(), ui->widget1->GetRenderWindow());

    boost::mutex mt;
    pcl::PointCloud<pcl::PointXYZ>::ConstPtr local_cloud;

    boost::function<void( const pcl::PointCloud<pcl::PointXYZ>::ConstPtr& )> func_cb =
            [&local_cloud, &mt]( const pcl::PointCloud<pcl::PointXYZ>::ConstPtr& ptr)
    {
        boost::mutex::scoped_lock lock(mt);
        local_cloud = ptr->makeShared();
    };

    pcl::Grabber *grabber_var = new pcl::io::OpenNI2Grabber();
    grabber_var->registerCallback(func_cb);

    grabber_var->start();

    int time = 0;
    while (time < 90)
    {
        boost::mutex::scoped_try_lock lock_mutex2 (mt);
        if( lock_mutex2.owns_lock() && local_cloud)
        {
            if (!viewer->updatePointCloud(local_cloud, "cloud"))
            {
                if (ui->z_axis_min->value() != 0 || ui->z_axis_max->value() != 0)
                {
                    pcl::PassThrough<pcl::PointXYZ> filter;
                    filter.setInputCloud(cloud);

                    filter.setFilterFieldName("z");

                    filter.setFilterLimits(ui->z_axis_min->value(),
                                           ui->z_axis_max->value());
                    filter.filter(*cloud);
                }

                viewer->addPointCloud(local_cloud, "cloud");
            }
            ui->widget1->update();
            clouds_vec.push_back(local_cloud);
            time++;
        }

    }

    grabber_var->stop();
}

void MainWindow::on_toolButton_clicked()
{
    flag = true;
    create_k2_visualizer();
}

void MainWindow::on_toolButton_2_clicked()
{
    flag = false;
}

void MainWindow::on_toolButton_3_clicked()
{
    if (ui->tri_comboBox->currentIndex() != -1)
    {
        if (flag_type == 0)
        {
            *poly_mesh = p2m.point2mesh(cloud, ui->tri_comboBox->currentIndex());
            ui->widget2->SetRenderWindow (viewer2->getRenderWindow());
            viewer2->setCameraPosition( 0.0, 0.0, -2.5, 0.0, 0.0, 0.0 );
            viewer2->setupInteractor (ui->widget2->GetInteractor(), ui->widget2->GetRenderWindow());
            viewer->addPolygonMesh(*poly_mesh, "meshes");
            ui->widget2->update();
        }
    }
}
