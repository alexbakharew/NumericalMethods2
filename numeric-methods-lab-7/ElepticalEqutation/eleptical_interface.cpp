#include <QMessageBox>
#include <iostream>
#include <string>
#include "eleptical_interface.h"
#include "ui_eleptical_interface.h"
#include "eleptical_solver.h"
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
    slv.Solve();

}
