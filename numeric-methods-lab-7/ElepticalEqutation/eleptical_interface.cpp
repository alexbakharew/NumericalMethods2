#include <QMessageBox>
#include <iostream>
#include <string>
#include "eleptical_interface.h"
#include "ui_eleptical_interface.h"
#include "eleptical_solver.h"
#include <fstream>
#include <string>
#include "solution_saver.h"
class ElepticalSolver;

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
    double N1, N2;
    try
    {
        N1 = std::stod(ui->lineEdit_N1->text().toStdString());
        N2 = std::stod(ui->lineEdit_N2->text().toStdString());
    }
    catch (...)
    {
        QMessageBox msg_box;
        msg_box.setText("All values should be numeric!");
        return;
    }
    ElepticalSolver slv(N1, N2);
    slv.InitMesh();
    //add analytic solution
    if(ui->radioButton_4->isChecked())
        slv.AnalyticSolution();
    else if(ui->radioButton->isChecked())
         slv.LibmanSolution();
    else if(ui->radioButton_2->isChecked())
        slv.SLAESolution(true);
    else if(ui->radioButton_3->isChecked())
        slv.SLAESolution(false);
    else
    {
        QMessageBox msg_box;
        msg_box.setText("Choose solution method!");
        return;
    }
    SolutionSaver::SaveResults(slv, "res.txt");
    //python script here
    this->close();
}
