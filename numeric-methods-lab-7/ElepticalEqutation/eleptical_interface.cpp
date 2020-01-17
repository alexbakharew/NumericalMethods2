#include <QMessageBox>
#include <iostream>
#include <string>
#include "eleptical_interface.h"
#include "ui_eleptical_interface.h"
#include "eleptical_solver.h"
#include <fstream>
#include <string>
#include "solution_saver.h"
#include <QProcess>
class ElepticalSolver;
const std::string python_script = "./draw_eleptical.py";
ElepticalInterface::ElepticalInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ElepticalInterface)
{
    ui->setupUi(this);
}

ElepticalInterface::~ElepticalInterface()
{
    delete ui;
}

void ElepticalInterface::on_pushButton_clicked()
{
    int N;
    double eps;
    try
    {
        N = std::stoi(ui->lineEdit_N->text().toStdString());
        eps = std::stod(ui->lineEdit_eps->text().toStdString());
    }
    catch (...)
    {
        QMessageBox msg_box;
        msg_box.setText("All values should be numeric!");
        return;
    }
    ElepticalSolver slv(N, eps);
    slv.InitMesh();
    std::string method_name;
    if(ui->radioButton_4->isChecked())
    {
        slv.AnalyticSolution();
        method_name = "Analytic";
    }
    else if(ui->radioButton->isChecked())
    {
         slv.LibmanSolution();
         method_name = "Libman";
    }
    else if(ui->radioButton_2->isChecked())
    {
        slv.SLAESolution(true);
        method_name = "Zeydel";
    }
    else if(ui->radioButton_3->isChecked())
    {
        slv.SLAESolution(false);
        method_name = "SimpleIteration";
    }
    else
    {
        QMessageBox msg_box;
        msg_box.setText("Choose solution method!");
        return;
    }
    SolutionSaver::SaveResults(slv, "res.txt");
    QProcess p;
    QStringList params;
    params << python_script.c_str() << std::to_string(N).c_str() << method_name.c_str();

    std::cout << p.startDetached("python3", params) << std::endl;
    p.waitForFinished(-1);
    this->close();
}
