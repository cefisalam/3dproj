/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qvtkwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_file;
    QAction *actionSave_file;
    QAction *actionAbout;
    QAction *actionOpen_files;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout;
    QVTKWidget *widget1;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QVTKWidget *widget2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QLabel *label_5;
    QDoubleSpinBox *x_min;
    QDoubleSpinBox *y_min;
    QDoubleSpinBox *x_max;
    QDoubleSpinBox *y_max;
    QSpacerItem *verticalSpacer;
    QDoubleSpinBox *z_axis_min;
    QLabel *label;
    QLabel *label_2;
    QToolButton *toolButton_4;
    QDoubleSpinBox *z_axis_max;
    QToolButton *toolButton_2;
    QToolButton *toolButton;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_7;
    QComboBox *sensor_comboBox;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QComboBox *tri_comboBox;
    QSpinBox *poisonSpinBox;
    QSpacerItem *verticalSpacer_2;
    QToolButton *toolButton_3;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1000, 733);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMaximumSize(QSize(1000, 800));
        actionOpen_file = new QAction(MainWindow);
        actionOpen_file->setObjectName(QStringLiteral("actionOpen_file"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/if_folder_orange_open_6868.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QStringLiteral(":/icons/resource/if_folder_orange_open_6868.png"), QSize(), QIcon::Normal, QIcon::On);
        icon.addFile(QStringLiteral(":/icons/resource/if_folder_orange_open_6868.png"), QSize(), QIcon::Disabled, QIcon::Off);
        icon.addFile(QStringLiteral(":/icons/resource/if_folder_orange_open_6868.png"), QSize(), QIcon::Disabled, QIcon::On);
        icon.addFile(QStringLiteral(":/icons/resource/if_folder_orange_open_6868.png"), QSize(), QIcon::Active, QIcon::Off);
        icon.addFile(QStringLiteral(":/icons/resource/if_folder_orange_open_6868.png"), QSize(), QIcon::Active, QIcon::On);
        icon.addFile(QStringLiteral(":/icons/resource/if_folder_orange_open_6868.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon.addFile(QStringLiteral(":/icons/resource/if_folder_orange_open_6868.png"), QSize(), QIcon::Selected, QIcon::On);
        actionOpen_file->setIcon(icon);
        actionOpen_file->setIconVisibleInMenu(true);
        actionSave_file = new QAction(MainWindow);
        actionSave_file->setObjectName(QStringLiteral("actionSave_file"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/if_filesaveas_6047.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QStringLiteral(":/icons/resource/if_filesaveas_6047.png"), QSize(), QIcon::Normal, QIcon::On);
        actionSave_file->setIcon(icon1);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/if_info_6077.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon2);
        actionOpen_files = new QAction(MainWindow);
        actionOpen_files->setObjectName(QStringLiteral("actionOpen_files"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/if_folder_new_6056.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen_files->setIcon(icon3);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        frame_3 = new QFrame(centralWidget);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget1 = new QVTKWidget(frame_3);
        widget1->setObjectName(QStringLiteral("widget1"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget1->sizePolicy().hasHeightForWidth());
        widget1->setSizePolicy(sizePolicy1);
        widget1->setMinimumSize(QSize(0, 250));
        widget1->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(widget1);


        gridLayout->addWidget(frame_3, 0, 2, 1, 1);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy2);
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        widget2 = new QVTKWidget(frame);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        verticalLayout_2->addWidget(widget2);


        gridLayout->addWidget(frame, 1, 2, 1, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 4, 0, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 6, 0, 1, 1);

        x_min = new QDoubleSpinBox(groupBox_2);
        x_min->setObjectName(QStringLiteral("x_min"));
        x_min->setMinimum(-99);
        x_min->setValue(-2);

        gridLayout_2->addWidget(x_min, 5, 0, 1, 1);

        y_min = new QDoubleSpinBox(groupBox_2);
        y_min->setObjectName(QStringLiteral("y_min"));
        y_min->setMinimum(-99);
        y_min->setValue(-2);

        gridLayout_2->addWidget(y_min, 7, 0, 1, 1);

        x_max = new QDoubleSpinBox(groupBox_2);
        x_max->setObjectName(QStringLiteral("x_max"));
        x_max->setMinimum(-99);
        x_max->setValue(2);

        gridLayout_2->addWidget(x_max, 5, 1, 1, 1);

        y_max = new QDoubleSpinBox(groupBox_2);
        y_max->setObjectName(QStringLiteral("y_max"));
        y_max->setMinimum(-99);
        y_max->setValue(2);

        gridLayout_2->addWidget(y_max, 7, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 9, 0, 1, 1);

        z_axis_min = new QDoubleSpinBox(groupBox_2);
        z_axis_min->setObjectName(QStringLiteral("z_axis_min"));
        z_axis_min->setMinimum(-99);
        z_axis_min->setValue(-2);

        gridLayout_2->addWidget(z_axis_min, 3, 0, 1, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 2, 0, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 2, 1, 1, 1);

        toolButton_4 = new QToolButton(groupBox_2);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(toolButton_4->sizePolicy().hasHeightForWidth());
        toolButton_4->setSizePolicy(sizePolicy3);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/if_edit_user_6020.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon4);
        toolButton_4->setIconSize(QSize(48, 48));
        toolButton_4->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout_2->addWidget(toolButton_4, 10, 0, 1, 2);

        z_axis_max = new QDoubleSpinBox(groupBox_2);
        z_axis_max->setObjectName(QStringLiteral("z_axis_max"));
        z_axis_max->setMinimum(-99);
        z_axis_max->setValue(2);

        gridLayout_2->addWidget(z_axis_max, 3, 1, 1, 1);

        toolButton_2 = new QToolButton(groupBox_2);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icons/if_player_stop_6158.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon5);
        toolButton_2->setIconSize(QSize(32, 32));
        toolButton_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout_2->addWidget(toolButton_2, 8, 1, 1, 1);

        toolButton = new QToolButton(groupBox_2);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icons/if_player_play_6154.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon6);
        toolButton->setIconSize(QSize(32, 32));
        toolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout_2->addWidget(toolButton, 8, 0, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 4, 1, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 6, 1, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 0, 0, 1, 1);

        sensor_comboBox = new QComboBox(groupBox_2);
        sensor_comboBox->setObjectName(QStringLiteral("sensor_comboBox"));

        gridLayout_2->addWidget(sensor_comboBox, 1, 0, 1, 2);


        gridLayout->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy4);
        groupBox->setMinimumSize(QSize(200, 0));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        tri_comboBox = new QComboBox(groupBox);
        tri_comboBox->setObjectName(QStringLiteral("tri_comboBox"));
        tri_comboBox->setEditable(true);
        tri_comboBox->setMaxVisibleItems(2);

        verticalLayout_3->addWidget(tri_comboBox);

        poisonSpinBox = new QSpinBox(groupBox);
        poisonSpinBox->setObjectName(QStringLiteral("poisonSpinBox"));
        poisonSpinBox->setEnabled(true);
        QSizePolicy sizePolicy5(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(poisonSpinBox->sizePolicy().hasHeightForWidth());
        poisonSpinBox->setSizePolicy(sizePolicy5);
        poisonSpinBox->setMinimum(1);
        poisonSpinBox->setMaximum(40);

        verticalLayout_3->addWidget(poisonSpinBox);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        toolButton_3 = new QToolButton(groupBox);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        QSizePolicy sizePolicy6(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(toolButton_3->sizePolicy().hasHeightForWidth());
        toolButton_3->setSizePolicy(sizePolicy6);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/icons/if_emerald-theme-manager_6296.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon7);
        toolButton_3->setIconSize(QSize(32, 32));
        toolButton_3->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        verticalLayout_3->addWidget(toolButton_3);


        gridLayout->addWidget(groupBox, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen_file);
        menuFile->addAction(actionOpen_files);
        menuFile->addAction(actionSave_file);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionOpen_file->setText(QApplication::translate("MainWindow", "Open file", Q_NULLPTR));
        actionSave_file->setText(QApplication::translate("MainWindow", "Save file", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("MainWindow", "About", Q_NULLPTR));
        actionOpen_files->setText(QApplication::translate("MainWindow", "Open files", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Acquisition Features", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "MIN (x axis)", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "MIN (y axis)", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "MIN (z axis)", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "MAX (z axis)", Q_NULLPTR));
        toolButton_4->setText(QApplication::translate("MainWindow", "Load\n"
"Aligned Points", Q_NULLPTR));
        toolButton_2->setText(QApplication::translate("MainWindow", "Stop \n"
"Acquisition", Q_NULLPTR));
        toolButton->setText(QApplication::translate("MainWindow", "Start \n"
"Acquisition", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "MAX (x axis)", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "MAX (y axis)", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        sensor_comboBox->clear();
        sensor_comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Kinect V1", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Kinect V2", Q_NULLPTR)
        );
        groupBox->setTitle(QApplication::translate("MainWindow", "Registration Features", Q_NULLPTR));
        tri_comboBox->clear();
        tri_comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Poisson", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Greedy", Q_NULLPTR)
        );
        tri_comboBox->setCurrentText(QApplication::translate("MainWindow", "Poisson", Q_NULLPTR));
        toolButton_3->setText(QApplication::translate("MainWindow", "Create\n"
"Triangle Mesh", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
