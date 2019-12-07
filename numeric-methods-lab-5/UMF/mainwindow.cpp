#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty() ||
            ui->lineEdit_3->text().isEmpty() || ui->lineEdit_4->text().isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("Please fill all values!");
        msgBox.exec();
        return;
    }
    N = ui->lineEdit->text().toStdString();
    K = ui->lineEdit_2->text().toStdString();
    l = ui->lineEdit_3->text().toStdString();
    T = ui->lineEdit_4->text().toStdString();
    if(ui->radioButton->isChecked())
    {
        method = MethodName::Explicit;
    }
    else if(ui->radioButton_2->isChecked())
    {
        method = MethodName::Implicit;
    }
    else if(ui->radioButton_3->isChecked())
    {
        method = MethodName::Crank_Nikolsn;
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Please choose solution method!");
        msgBox.exec();

        return;
    }

    std::fstream config_file("config.cfg", std::ios::out);

    if(!config_file.is_open())
    {
        QMessageBox msgBox;
        msgBox.setText("Can not save config file");
        msgBox.exec();
        return;
    }

    config_file << N << " " << K << std::endl;
    config_file << l << " " << T << std::endl;
    config_file << method << std::endl;
    ui->~MainWindow();
}

