/********************************************************************************
** Form generated from reading UI file 'parabolic_interface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARABOLIC_INTERFACE_H
#define UI_PARABOLIC_INTERFACE_H

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

class Ui_ParabolicInterface
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QRadioButton *radioButton;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QRadioButton *radioButton_4;
    QLabel *label_8;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_9;
    QLineEdit *lineEdit_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *ParabolicInterface)
    {
        if (ParabolicInterface->objectName().isEmpty())
            ParabolicInterface->setObjectName(QString::fromUtf8("ParabolicInterface"));
        ParabolicInterface->resize(501, 333);
        centralwidget = new QWidget(ParabolicInterface);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setChecked(true);

        gridLayout->addWidget(radioButton, 2, 4, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 1, 2, 5, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 6, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 6, 5, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 6, 1, 1, 4);

        radioButton_4 = new QRadioButton(centralwidget);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));

        gridLayout->addWidget(radioButton_4, 1, 4, 1, 1);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 0, 4, 1, 2, Qt::AlignHCenter|Qt::AlignVCenter);

        radioButton_3 = new QRadioButton(centralwidget);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        gridLayout->addWidget(radioButton_3, 4, 4, 1, 1);

        radioButton_2 = new QRadioButton(centralwidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        gridLayout->addWidget(radioButton_2, 3, 4, 1, 1);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 2, 1, 1, 1);

        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 3, 1, 1, 1);

        lineEdit_5 = new QLineEdit(centralwidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        gridLayout->addWidget(lineEdit_5, 4, 1, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1, Qt::AlignHCenter);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1, Qt::AlignHCenter);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1, Qt::AlignHCenter);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1, Qt::AlignHCenter);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1, Qt::AlignHCenter);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 1, 1, 1);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 5, 0, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 5, 4, 1, 1, Qt::AlignHCenter);

        lineEdit_6 = new QLineEdit(centralwidget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        gridLayout->addWidget(lineEdit_6, 5, 5, 1, 1);

        ParabolicInterface->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ParabolicInterface);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 501, 22));
        ParabolicInterface->setMenuBar(menubar);
        statusbar = new QStatusBar(ParabolicInterface);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ParabolicInterface->setStatusBar(statusbar);
        toolBar = new QToolBar(ParabolicInterface);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        ParabolicInterface->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(ParabolicInterface);
        toolBar_2->setObjectName(QString::fromUtf8("toolBar_2"));
        ParabolicInterface->addToolBar(Qt::TopToolBarArea, toolBar_2);

        retranslateUi(ParabolicInterface);

        QMetaObject::connectSlotsByName(ParabolicInterface);
    } // setupUi

    void retranslateUi(QMainWindow *ParabolicInterface)
    {
        ParabolicInterface->setWindowTitle(QApplication::translate("ParabolicInterface", "ParabolicInterface", nullptr));
        radioButton->setText(QApplication::translate("ParabolicInterface", "Explicit", nullptr));
        pushButton->setText(QApplication::translate("ParabolicInterface", "Solve", nullptr));
        radioButton_4->setText(QApplication::translate("ParabolicInterface", "Analytic", nullptr));
        label_8->setText(QApplication::translate("ParabolicInterface", "Choose solution method", nullptr));
        radioButton_3->setText(QApplication::translate("ParabolicInterface", "Crank-Nikolsn", nullptr));
        radioButton_2->setText(QApplication::translate("ParabolicInterface", "Implicit", nullptr));
        lineEdit->setText(QApplication::translate("ParabolicInterface", "10", nullptr));
        lineEdit_2->setText(QApplication::translate("ParabolicInterface", "20", nullptr));
        lineEdit_3->setText(QApplication::translate("ParabolicInterface", "3.14159", nullptr));
        lineEdit_4->setText(QApplication::translate("ParabolicInterface", "20", nullptr));
        lineEdit_5->setText(QApplication::translate("ParabolicInterface", "0.2", nullptr));
        label->setText(QApplication::translate("ParabolicInterface", "N = ", nullptr));
        label_2->setText(QApplication::translate("ParabolicInterface", "K = ", nullptr));
        label_3->setText(QApplication::translate("ParabolicInterface", "l = ", nullptr));
        label_4->setText(QApplication::translate("ParabolicInterface", "T = ", nullptr));
        label_5->setText(QApplication::translate("ParabolicInterface", "a = ", nullptr));
        label_6->setText(QApplication::translate("ParabolicInterface", "TextLabel", nullptr));
        label_7->setText(QApplication::translate("ParabolicInterface", "sigma = ", nullptr));
        label_9->setText(QApplication::translate("ParabolicInterface", "teta = ", nullptr));
        toolBar->setWindowTitle(QApplication::translate("ParabolicInterface", "toolBar", nullptr));
        toolBar_2->setWindowTitle(QApplication::translate("ParabolicInterface", "toolBar_2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ParabolicInterface: public Ui_ParabolicInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARABOLIC_INTERFACE_H
