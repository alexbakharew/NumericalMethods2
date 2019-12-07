#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    if(ui->lineEdit->text().isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("The document has been modified.");
        msgBox.exec();
    }
    std::string a = ui->lineEdit->text().toStdString();
    std::string b = ui->lineEdit_2->text().toStdString();
    std::string c = ui->lineEdit_3->text().toStdString();
    std::string d = ui->lineEdit_4->text().toStdString();
    std::string e = ui->lineEdit_5->text().toStdString();
    std::string f = ui->lineEdit_6->text().toStdString();
    std::string g = ui->lineEdit_7->text().toStdString();
}
