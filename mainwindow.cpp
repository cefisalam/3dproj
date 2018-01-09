#include "mainwindow.h"
#include "ui_mainwindow.h"

//Constructor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    clouds_vec (0),
    cloud (new pcl::PointCloud<pcl::PointXYZRGBA>()),
    p2m (nullptr),
    flag(false),
    poly_mesh (new pcl::PolygonMesh)
{
    ui->setupUi(this);
    this->setWindowTitle("3D-V2 Scanner");
    viewer.reset(new pcl::visualization::PCLVisualizer("Viewer K2", true));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Function to insert loaded .pcd database into vector for registration/triangulation
void MainWindow::load_pcd_files(QStringList files_pcd)
{
    for (int i = 0; i < files_pcd.size(); i++)
    {
        pcl::PointCloud<pcl::PointXYZRGBA>::Ptr pcd (new pcl::PointCloud<pcl::PointXYZRGBA>());
        pcl::io::loadPCDFile(files_pcd.at(i).toStdString(), *pcd);
        std::cout << files_pcd.at(i).toStdString() << std::endl;
        clouds_vec.push_back(pcd);
    }
}

//Function to load all kinds of point clouds/mesh (ply, vtk, obj, pcd)
void MainWindow::on_actionOpen_file_triggered()
{

    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer2;
    viewer.reset (new pcl::visualization::PCLVisualizer ("viewer", false));
    viewer2.reset (new pcl::visualization::PCLVisualizer ("viewer2", false));
    viewer->setCameraPosition( 0.0, 0.0, -2.5, 0.0 , 0.0 , 0.0 );

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

//Function to save displayed point/meshes into respective files
void MainWindow::on_actionSave_file_triggered()
{
    if (flag_type == -1)
    {
        QMessageBox msg;
        msg.setInformativeText("No file to be save");
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
                                                         tr("STL (*.stl)"));
        pcl::io::savePolygonFileSTL(file_name.toStdString(), *poly_mesh);
    }

    else if (flag_type == 3)
    {
        QString file_name = QFileDialog::getSaveFileName(this, tr("Save file"), "",
                                                         tr("VTK (*.vtk)"));
        pcl::io::savePolygonFileVTK(file_name.toStdString(), *poly_mesh);
    }
}

//Function to handle the grabber for Kinect V2 and saves the set of point clouds
void MainWindow::on_toolButton_clicked()
{
    flag = true;
    viewer->setCameraPosition( 0.0, 0.0, -2.5, 0.0 , 0.0 , 0.0 );

    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud_filter1 (new pcl::PointCloud<pcl::PointXYZRGBA>);
    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud_filter2 (new pcl::PointCloud<pcl::PointXYZRGBA>);
    pcl::PassThrough<pcl::PointXYZRGBA> filter;
    boost::mutex mt;
    pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr local_cloud;

    boost::function<void(const pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr& )> func_cb =
            [&local_cloud, &mt]( const pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr& ptr)
    {
        boost::mutex::scoped_lock lock (mt);
        local_cloud = ptr->makeShared();
    };

    boost::function<void(const pcl::visualization::KeyboardEvent& )> key_func =
            [&local_cloud, &mt, &cloud_filter1]( const pcl::visualization::KeyboardEvent& event ){
        if( event.getKeySym() == "s" && event.keyDown() ){
            boost::mutex::scoped_lock lock( mt );

            static uint32_t count = 0;
            std::ostringstream str_file;
            str_file << std::setfill( '0' ) << std::setw( 3 ) << count++;
            std::cout << str_file.str() + ".pcd\n";
            pcl::io::savePCDFile( str_file.str() + ".pcd", *cloud_filter1, false );
        }
    };

    viewer->registerKeyboardCallback(key_func);

    if (ui->sensor_comboBox->currentIndex() == 0)
    {
        pcl::Grabber *grabber = new pcl::io::OpenNI2Grabber();
        boost::signals2::connection conn = grabber->registerCallback(func_cb);
        grabber->start();

        int i = 0;
        while (flag)
        {
            viewer->spinOnce();
            boost::mutex::scoped_try_lock lock (mt);
            if(lock.owns_lock() && local_cloud)
            {
                filter.setFilterFieldName ("x");
                filter.setFilterLimits (ui->x_min->value(), ui->x_max->value());
                filter.setInputCloud (local_cloud);
                filter.filter (*cloud_filter1);

                filter.setFilterFieldName ("y");
                filter.setFilterLimits (ui->y_min->value(), ui->y_max->value());
                filter.setInputCloud (cloud_filter1);
                filter.filter (*cloud_filter2);

                filter.setFilterFieldName ("z");
                filter.setFilterLimits (ui->z_axis_min->value(), ui->z_axis_max->value());
                filter.setInputCloud (cloud_filter2);
                filter.filter (*cloud_filter1);
            }

            if (!viewer->updatePointCloud(cloud_filter1, "cloud"))
            {
                viewer->addPointCloud(cloud_filter1, "cloud");
            }

            clouds_vec.push_back(cloud_filter1);
        }

        grabber->stop();
        flag_type = 5;
    }

    else if (ui->sensor_comboBox->currentIndex() == 1)
    {
        boost::shared_ptr<pcl::Grabber> grabber = boost::make_shared<pcl::Kinect2Grabber>();
        boost::signals2::connection conn = grabber->registerCallback(func_cb);
        grabber->start();

        int i = 0;
        while (flag)
        {
            viewer->spinOnce();
            boost::mutex::scoped_try_lock lock (mt);
            if(lock.owns_lock() && local_cloud)
            {

                filter.setFilterFieldName ("x");
                filter.setFilterLimits (ui->x_min->value(), ui->x_max->value());
                filter.setInputCloud (local_cloud);
                filter.filter (*cloud_filter1);

                filter.setFilterFieldName ("y");
                filter.setFilterLimits (ui->y_min->value(), ui->y_max->value());
                filter.setInputCloud (cloud_filter1);
                filter.filter (*cloud_filter2);

                filter.setFilterFieldName ("z");
                filter.setFilterLimits (ui->z_axis_min->value(), ui->z_axis_max->value());
                filter.setInputCloud (cloud_filter2);
                filter.filter (*cloud_filter1);

            }

            if (!viewer->updatePointCloud(cloud_filter1, "cloud"))
            {
                viewer->addPointCloud(cloud_filter1, "cloud");
            }

            clouds_vec.push_back(cloud_filter1);

        }

        grabber->stop();
        flag_type = 5;
    }

}

//Function to stop the grabber for recording point clouds
void MainWindow::on_toolButton_2_clicked()
{
    flag = false;
    viewer->close();
    qDebug() << "CLOUD_SIZE: " << clouds_vec.size();
}

//Function to perform triangulation into displayed point cloud
void MainWindow::on_toolButton_3_clicked()
{
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer2;
    viewer2.reset(new pcl::visualization::PCLVisualizer("Viewer K2", false));
    if (ui->tri_comboBox->currentIndex() != -1)
    {
        if (flag_type == 0 || flag_type == 5)
        {
            if (ui->tri_comboBox->currentIndex() == 0)
            {
                p2m.point2mesh(cloud, ui->tri_comboBox->currentIndex(), ui->poisonSpinBox->value());
                qDebug() << "Depth set: " << ui->poisonSpinBox->value();
            }

            else
            {
                p2m.point2mesh(cloud, ui->tri_comboBox->currentIndex(), 0);
            }

            ui->widget2->SetRenderWindow (viewer2->getRenderWindow());
            viewer2->setupInteractor (ui->widget2->GetInteractor(), ui->widget2->GetRenderWindow());

            if (viewer2->removeAllShapes())
            {
                if (pcl::io::loadPolygonFileSTL("tri.stl", *poly_mesh) != -1)
                {
                    viewer2->addPolygonMesh(*poly_mesh, "meshes");
                    ui->widget2->update();
                }
            }
        }

        else
        {
            QMessageBox msg;
            msg.setInformativeText("No POINT CLOUD to triangulate");
            msg.exec();
        }
    }
}

//Function to load user file set of point clouds into vector for align/triangulation
void MainWindow::on_actionOpen_files_triggered()
{
    clouds_vec.clear();

    QStringList files_pcd = QFileDialog::getOpenFileNames(this, tr("Open mesh file"),
                                                          "C:/",
                                                          tr("Meshes *.ply *.obj *.vtk *.pcd *.stl"));


    load_pcd_files(files_pcd);
    flag = 4;
}

//Function to align the loaded set of point clouds
void MainWindow::on_toolButton_4_clicked()
{
    if (!clouds_vec.empty() || flag == 4)
    {
        k2class kinect;
        kinect.registration(clouds_vec);
    }

    else
    {
        QMessageBox msg;
        msg.setInformativeText("No file to be align");
        msg.exec();
    }
}
