#-------------------------------------------------
#
# Project created by QtCreator 2018-01-02T16:02:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 3dproj
TEMPLATE = app
CONFIG += c++11

INCLUDEPATH += "C:\Program Files\PCL 1.8.1\include\pcl-1.8"
INCLUDEPATH += "C:\Program Files\PCL 1.8.1\3rdParty\Boost\include\boost-1_64"
INCLUDEPATH += "C:\Program Files\PCL 1.8.1\3rdParty\Qhull\include"
INCLUDEPATH += "C:\Program Files\PCL 1.8.1\3rdParty\FLANN\include"
INCLUDEPATH += "C:\Program Files\PCL 1.8.1\3rdParty\Eigen\eigen3"
INCLUDEPATH += "C:\Program Files\VTK\include\vtk-8.0"
INCLUDEPATH += "C:\Program Files\OpenNI2\Include"
INCLUDEPATH += "C:\Program Files\Microsoft SDKs\Kinect\v1.8\inc"
INCLUDEPATH += "C:\Program Files\Microsoft SDKs\Kinect\v2.0_1409\inc"

LIBS += "-LC:\Program Files (x86)\Windows Kits\10\Lib\10.0.16299.0\um\x64"
LIBS += "-LC:\Program Files\Microsoft SDKs\Kinect\v1.8\lib\amd64"
LIBS += "-LC:\Program Files\Microsoft SDKs\Kinect\v1.8\Assemblies"
LIBS += "-LC:\Program Files\Microsoft SDKs\Kinect\v2.0_1409\Lib\x64"

INCLUDEPATH += "C:\Program Files (x86)\Windows Kits\10\Include\10.0.10240.0\um"
INCLUDEPATH += "C:\Program Files (x86)\Windows Kits\10\Include\10.0.10240.0\shared"
LIBS += opengl32.lib advapi32.lib Ws2_32.lib user32.lib shell32.lib gdi32.lib kernel32.lib

#LIBS += -lOpenGL32 -lAdvAPI32 -lWS2_32 -lUser32 -lshell32 -Gdi32 -lkernel32
LIBS += OpenGL32.lib AdvAPI32.lib WS2_32.lib User32.lib shell32.lib Gdi32.lib kernel32.lib
LIBS += opengl32.lib advapi32.lib Ws2_32.lib user32.lib shell32.lib gdi32.lib kernel32.lib

LIBS += "-LC:\Program Files\PCL 1.8.1\lib"
#LIBS += "-LC:\Program Files\PCL 1.8.1\bin"
LIBS += "-LC:\Program Files\PCL 1.8.1\3rdParty\Qhull\lib"
LIBS += "-LC:\Program Files\PCL 1.8.1\3rdParty\FLANN\lib"
LIBS += "-LC:\Program Files\PCL 1.8.1\3rdParty\Boost\lib"
LIBS += "-LC:\Program Files\VTK\lib"
LIBS += "-LC:\Program Files\VTK\bin"
LIBS += "-LC:\Program Files\OpenNI2\Lib"
LIBS += "-LC:\Program Files\OpenNI2\Tools"
LIBS += "-LC:\Program Files\OpenNI2\Tools\OpenNI2\Drivers"

#LIBS += -lMicrosoft.Kinect
LIBS += -lKinect20
LIBS += -lKinect10
LIBS += -lflann_cpp_s
LIBS += -lflann_s
LIBS += -lflann
LIBS += -lqhullstatic
LIBS += -lOpenNI2
LIBS += -glut64
#LIBS += -lPSLink
#LIBS += -lKinect
#LIBS += -lOniFile
#LIBS += -lPS1080

LIBS += -lpcl_common_release
LIBS += -lpcl_features_release
LIBS += -lpcl_filters_release
LIBS += -lpcl_io_ply_release
LIBS += -lpcl_io_release
LIBS += -lpcl_kdtree_release
LIBS += -lpcl_keypoints_release
LIBS += -lpcl_ml_release
LIBS += -lpcl_octree_release
LIBS += -lpcl_outofcore_release
LIBS += -lpcl_people_release
LIBS += -lpcl_recognition_release
LIBS += -lpcl_registration_release
LIBS += -lpcl_sample_consensus_release
LIBS += -lpcl_search_release
LIBS += -lpcl_segmentation_release
LIBS += -lpcl_stereo_release
LIBS += -lpcl_surface_release
LIBS += -lpcl_tracking_release
LIBS += -lpcl_visualization_release

LIBS += -llibboost_graph-vc140-mt-gd-1_64
LIBS += -llibboost_iostreams-vc140-mt-1_64
LIBS += -llibboost_iostreams-vc140-mt-gd-1_64
LIBS += -llibboost_locale-vc140-mt-1_64
LIBS += -llibboost_locale-vc140-mt-gd-1_64
LIBS += -llibboost_log_setup-vc140-mt-1_64
LIBS += -llibboost_log_setup-vc140-mt-gd-1_64
LIBS += -llibboost_log-vc140-mt-1_64
LIBS += -llibboost_log-vc140-mt-gd-1_64
LIBS += -llibboost_math_c99f-vc140-mt-1_64
LIBS += -llibboost_math_c99f-vc140-mt-gd-1_64
LIBS += -llibboost_math_c99l-vc140-mt-1_64
LIBS += -llibboost_math_c99l-vc140-mt-gd-1_64
LIBS += -llibboost_math_c99-vc140-mt-1_64
LIBS += -llibboost_math_c99-vc140-mt-gd-1_64
LIBS += -llibboost_math_tr1f-vc140-mt-1_64
LIBS += -llibboost_math_tr1f-vc140-mt-gd-1_64
LIBS += -llibboost_math_tr1l-vc140-mt-1_64
LIBS += -llibboost_math_tr1l-vc140-mt-gd-1_64
LIBS += -llibboost_math_tr1-vc140-mt-1_64
LIBS += -llibboost_math_tr1-vc140-mt-gd-1_64
LIBS += -llibboost_mpi-vc140-mt-1_64
LIBS += -llibboost_mpi-vc140-mt-gd-1_64
LIBS += -llibboost_numpy3-vc140-mt-1_64
LIBS += -llibboost_numpy3-vc140-mt-gd-1_64
LIBS += -llibboost_numpy-vc140-mt-1_64
LIBS += -llibboost_numpy-vc140-mt-gd-1_64
LIBS += -llibboost_prg_exec_monitor-vc140-mt-1_64
LIBS += -llibboost_prg_exec_monitor-vc140-mt-gd-1_64
LIBS += -llibboost_program_options-vc140-mt-1_64
LIBS += -llibboost_program_options-vc140-mt-gd-1_64
LIBS += -llibboost_python3-vc140-mt-1_64
LIBS += -llibboost_python3-vc140-mt-gd-1_64
LIBS += -llibboost_python-vc140-mt-1_64
LIBS += -llibboost_python-vc140-mt-gd-1_64
LIBS += -llibboost_random-vc140-mt-1_64
LIBS += -llibboost_random-vc140-mt-gd-1_64
LIBS += -llibboost_regex-vc140-mt-1_64
LIBS += -llibboost_regex-vc140-mt-gd-1_64
LIBS += -llibboost_serialization-vc140-mt-1_64
LIBS += -llibboost_serialization-vc140-mt-gd-1_64
LIBS += -llibboost_signals-vc140-mt-1_64
LIBS += -llibboost_signals-vc140-mt-gd-1_64
LIBS += -llibboost_system-vc140-mt-1_64
LIBS += -llibboost_system-vc140-mt-gd-1_64
LIBS += -llibboost_test_exec_monitor-vc140-mt-1_64
LIBS += -llibboost_test_exec_monitor-vc140-mt-gd-1_64
LIBS += -llibboost_thread-vc140-mt-1_64
LIBS += -llibboost_thread-vc140-mt-gd-1_64
LIBS += -llibboost_timer-vc140-mt-1_64
LIBS += -llibboost_timer-vc140-mt-gd-1_64
LIBS += -llibboost_type_erasure-vc140-mt-1_64
LIBS += -llibboost_type_erasure-vc140-mt-gd-1_64
LIBS += -llibboost_unit_test_framework-vc140-mt-1_64
LIBS += -llibboost_unit_test_framework-vc140-mt-gd-1_64
LIBS += -llibboost_wave-vc140-mt-1_64
LIBS += -llibboost_wave-vc140-mt-gd-1_64
LIBS += -llibboost_wserialization-vc140-mt-1_64
LIBS += -llibboost_wserialization-vc140-mt-gd-1_64
LIBS += -llibboost_zlib-vc140-mt-1_64
LIBS += -llibboost_zlib-vc140-mt-gd-1_64
LIBS += -llibboost_atomic-vc140-mt-1_64
LIBS += -llibboost_atomic-vc140-mt-gd-1_64
LIBS += -llibboost_bzip2-vc140-mt-1_64
LIBS += -llibboost_bzip2-vc140-mt-gd-1_64
LIBS += -llibboost_chrono-vc140-mt-1_64
LIBS += -llibboost_chrono-vc140-mt-gd-1_64
LIBS += -llibboost_container-vc140-mt-1_64
LIBS += -llibboost_container-vc140-mt-gd-1_64
LIBS += -llibboost_context-vc140-mt-1_64
LIBS += -llibboost_context-vc140-mt-gd-1_64
LIBS += -llibboost_coroutine-vc140-mt-1_64
LIBS += -llibboost_coroutine-vc140-mt-gd-1_64
LIBS += -llibboost_date_time-vc140-mt-1_64
LIBS += -llibboost_date_time-vc140-mt-gd-1_64
LIBS += -llibboost_exception-vc140-mt-1_64
LIBS += -llibboost_exception-vc140-mt-gd-1_64
LIBS += -llibboost_fiber-vc140-mt-1_64
LIBS += -llibboost_fiber-vc140-mt-gd-1_64
LIBS += -llibboost_filesystem-vc140-mt-1_64
LIBS += -llibboost_filesystem-vc140-mt-gd-1_64
LIBS += -llibboost_graph_parallel-vc140-mt-1_64
LIBS += -llibboost_graph_parallel-vc140-mt-gd-1_64
LIBS += -llibboost_graph-vc140-mt-1_64

LIBS += -lvtkViewsQt-8.0
LIBS += -lvtkRenderingQt-8.0
LIBS += -lvtkGeovisCore-8.0
LIBS += -lvtkViewsInfovis-8.0
LIBS += -lvtkGUISupportQt-8.0
LIBS += -lvtkIOExportOpenGL2-8.0
LIBS += -lvtkViewsContext2D-8.0
LIBS += -lvtkIOExport-8.0
LIBS += -lvtkInteractionImage-8.0
LIBS += -lvtkDomainsChemistryOpenGL2-8.0
LIBS += -lvtkRenderingVolumeOpenGL2-8.0
LIBS += -lvtkRenderingContextOpenGL2-8.0
LIBS += -lvtkIOParallel-8.0
LIBS += -lvtkViewsCore-8.0
LIBS += -lvtkRenderingGL2PSOpenGL2-8.0
LIBS += -lvtkRenderingOpenGL2-8.0
LIBS += -lvtkInteractionWidgets-8.0
LIBS += -lvtkIOMINC-8.0
LIBS += -lvtkTestingRendering-8.0
LIBS += -lvtkChartsCore-8.0
LIBS += -lvtkIOImport-8.0
LIBS += -lvtkRenderingImage-8.0
LIBS += -lvtkRenderingLOD-8.0
LIBS += -lvtkRenderingLabel-8.0
LIBS += -lvtkFiltersParallel-8.0
LIBS += -lvtkDomainsChemistry-8.0
LIBS += -lvtkRenderingContext2D-8.0
LIBS += -lvtkRenderingVolume-8.0
LIBS += -lvtkFiltersHybrid-8.0
LIBS += -lvtkRenderingAnnotation-8.0
LIBS += -lvtkInteractionStyle-8.0
LIBS += -lvtkRenderingFreeType-8.0
LIBS += -lvtkRenderingCore-8.0
LIBS += -lvtkInfovisLayout-8.0
LIBS += -lvtkFiltersGeneric-8.0
LIBS += -lvtkFiltersModeling-8.0
LIBS += -lvtkIOInfovis-8.0
LIBS += -lvtkFiltersFlowPaths-8.0
LIBS += -lvtkInfovisCore-8.0
LIBS += -lvtkFiltersSources-8.0
LIBS += -lvtkIOLSDyna-8.0
LIBS += -lvtkFiltersHyperTree-8.0
LIBS += -lvtkFiltersSMP-8.0
LIBS += -lvtkFiltersExtraction-8.0
LIBS += -lvtkFiltersTexture-8.0
LIBS += -lvtkFiltersPoints-8.0
LIBS += -lvtkImagingMorphological-8.0
LIBS += -lvtkIOEnSight-8.0
LIBS += -lvtkFiltersGeneral-8.0
LIBS += -lvtkIOVideo-8.0
LIBS += -lvtkFiltersProgrammable-8.0
LIBS += -lvtkTestingIOSQL-8.0
LIBS += -lvtkFiltersTopology-8.0
LIBS += -lvtkImagingStencil-8.0
LIBS += -lvtkIOPLY-8.0
LIBS += -lvtkIOMovie-8.0
LIBS += -lvtkIOExodus-8.0
LIBS += -lvtkIOAMR-8.0
LIBS += -lvtkImagingStatistics-8.0
LIBS += -lvtkIOParallelXML-8.0
LIBS += -lvtkIOTecplotTable-8.0
LIBS += -lvtkFiltersVerdict-8.0
LIBS += -lvtkGUISupportQtSQL-8.0
LIBS += -lvtkFiltersSelection-8.0
LIBS += -lvtkFiltersAMR-8.0
LIBS += -lvtkIOGeometry-8.0
LIBS += -lvtkIOSQL-8.0
LIBS += -lvtkImagingMath-8.0
LIBS += -lvtkIONetCDF-8.0
LIBS += -lvtkImagingHybrid-8.0
LIBS += -lvtkFiltersImaging-8.0
LIBS += -lvtkFiltersGeometry-8.0
LIBS += -lvtkIOImage-8.0
LIBS += -lvtkParallelCore-8.0
LIBS += -lvtkIOLegacy-8.0
LIBS += -lvtkImagingGeneral-8.0
LIBS += -lvtkFiltersCore-8.0
LIBS += -lvtkImagingColor-8.0
LIBS += -lvtkImagingSources-8.0
LIBS += -lvtkFiltersStatistics-8.0
LIBS += -lvtkIOXML-8.0
LIBS += -lvtkImagingFourier-8.0
LIBS += -lvtkImagingCore-8.0
LIBS += -lvtkIOXMLParser-8.0
LIBS += -lvtkIOCore-8.0
LIBS += -lvtkCommonExecutionModel-8.0
LIBS += -lvtkCommonComputationalGeometry-8.0
LIBS += -lvtkTestingGenericBridge-8.0
LIBS += -lvtkCommonColor-8.0
LIBS += -lvtkCommonDataModel-8.0
LIBS += -lvtkCommonTransforms-8.0
LIBS += -lvtkCommonMisc-8.0
LIBS += -lvtkCommonMath-8.0
LIBS += -lvtkCommonSystem-8.0
LIBS += -lvtkCommonCore-8.0
LIBS += -lvtkexoIIc-8.0
LIBS += -lvtkNetCDF-8.0
LIBS += -lvtkhdf5_hl-8.0
LIBS += -lvtkhdf5-8.0
LIBS += -lvtkproj4-8.0
LIBS += -lvtklibxml2-8.0
LIBS += -lvtkverdict-8.0
LIBS += -lvtkjsoncpp-8.0
LIBS += -lvtklibharu-8.0
LIBS += -lvtkoggtheora-8.0
LIBS += -lvtksqlite-8.0
LIBS += -lvtkglew-8.0
LIBS += -lvtkgl2ps-8.0
LIBS += -lvtktiff-8.0
LIBS += -lvtkfreetype-8.0
LIBS += -lvtkDICOMParser-8.0
LIBS += -lvtkmetaio-8.0
LIBS += -lvtkjpeg-8.0
LIBS += -lvtksys-8.0
LIBS += -lvtkalglib-8.0
LIBS += -lvtkpng-8.0
LIBS += -lvtkexpat-8.0
LIBS += -lvtkzlib-8.0
LIBS += -lvtklz4-8.0
LIBS += -lvtkFiltersParallelImaging-8.0


DEFINES += QT_DEPRECATED_WARNINGS



SOURCES += \
        main.cpp \
        mainwindow.cpp \
    k1class.cpp \
    point2mesh.cpp

HEADERS += \
        mainwindow.h \
    k1class.h \
    point2mesh.h \
    pointa.h

FORMS += \
        mainwindow.ui
