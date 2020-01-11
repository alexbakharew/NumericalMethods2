/********************************************************************************
** Form generated from reading UI file 'hyperbolic_interface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HYPERBOLIC_INTERFACE_H
#define UI_HYPERBOLIC_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HyperbolicInterface
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label_8;
    QRadioButton *radioButton_2;
    QLabel *label_3;
    QLabel *label;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_4;
    QSpacerItem *horizontalSpacer;
    QLabel *label_9;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton;
    QLabel *label_4;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_5;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *HyperbolicInterface)
    {
        if (HyperbolicInterface->objectName().isEmpty())
            HyperbolicInterface->setObjectName(QString::fromUtf8("HyperbolicInterface"));
        HyperbolicInterface->resize(514, 273);
        centralwidget = new QWidget(HyperbolicInterface);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 5, 1, 1, 1);

        radioButton_2 = new QRadioButton(centralwidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        gridLayout->addWidget(radioButton_2, 3, 3, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 3, 1, 1, 1);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 1, 1, 1);

        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 4, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 5, 0, 1, 1);

        radioButton_3 = new QRadioButton(centralwidget);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        gridLayout->addWidget(radioButton_3, 4, 3, 1, 1);

        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        gridLayout->addWidget(radioButton, 2, 3, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 2, 1, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 1, 3, 1, 2);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 5, 2, 1, 1);

        HyperbolicInterface->setCentralWidget(centralwidget);
        menubar = new QMenuBar(HyperbolicInterface);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 514, 22));
        HyperbolicInterface->setMenuBar(menubar);
        statusbar = new QStatusBar(HyperbolicInterface);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        HyperbolicInterface->setStatusBar(statusbar);
        toolBar = new QToolBar(HyperbolicInterface);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        HyperbolicInterface->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(HyperbolicInterface);

        QMetaObject::connectSlotsByName(HyperbolicInterface);
    } // setupUi

    void retranslateUi(QMainWindow *HyperbolicInterface)
    {
        HyperbolicInterface->setWindowTitle(QApplication::translate("HyperbolicInterface", "MainWindow", nullptr));
        label_8->setText(QString());
        radioButton_2->setText(QApplication::translate("HyperbolicInterface", "Explicit", nullptr));
        label_3->setText(QApplication::translate("HyperbolicInterface", "T = ", nullptr));
        label->setText(QApplication::translate("HyperbolicInterface", "N = ", nullptr));
        label_9->setText(QApplication::translate("HyperbolicInterface", "sigma = ", nullptr));
        radioButton_3->setText(QApplication::translate("HyperbolicInterface", "Implicit", nullptr));
        radioButton->setText(QApplication::translate("HyperbolicInterface", "Analytic", nullptr));
        label_4->setText(QApplication::translate("HyperbolicInterface", "K = ", nullptr));
        label_2->setText(QApplication::translate("HyperbolicInterface", "l = ", nullptr));
        label_5->setText(QApplication::translate("HyperbolicInterface", "Choose Solution Method", nullptr));
        pushButton->setText(QApplication::translate("HyperbolicInterface", "PushButton", nullptr));
        toolBar->setWindowTitle(QApplication::translate("HyperbolicInterface", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HyperbolicInterface: public Ui_HyperbolicInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HYPERBOLIC_INTERFACE_H
