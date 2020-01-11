#include "hyperbolic_interface.h"
#include "ui_hyperbolic_interface.h"

HyperbolicInterface::HyperbolicInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HyperbolicInterface)
{
    ui->setupUi(this);
}

HyperbolicInterface::~HyperbolicInterface()
{
    delete ui;
}

void HyperbolicInterface::on_pushButton_clicked()
{

}
