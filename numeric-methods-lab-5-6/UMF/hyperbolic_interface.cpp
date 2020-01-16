#include "hyperbolic_interface.h"
#include "ui_hyperbolic_interface.h"
#include <QMessageBox>
#include <fstream>
HyperbolicInterface::HyperbolicInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HyperbolicInterface)
{
    ui->setupUi(this);
    ui->label_8->setText(std::to_string(CalculateSigma()).c_str());
}

HyperbolicInterface::~HyperbolicInterface()
{
    delete ui;
}

void HyperbolicInterface::on_pushButton_clicked()
{
    if(ui->lineEdit_N->text().isEmpty() || ui->lineEdit_K->text().isEmpty() ||
            ui->lineEdit_l->text().isEmpty() || ui->lineEdit_T->text().isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("Please fill all values!");
        msgBox.exec();
        return;
    }
    N = ui->lineEdit_N->text().toStdString();
    K = ui->lineEdit_K->text().toStdString();
    l = ui->lineEdit_l->text().toStdString();
    T = ui->lineEdit_T->text().toStdString();

    if(ui->radioButton->isChecked())
    {
        method = MethodName::Analytic;
    }
    else if(ui->radioButton_2->isChecked())
    {
        method = MethodName::Explicit;
    }
    else if(ui->radioButton_3->isChecked())
    {
        method = MethodName::Implicit;
    }
    else exit(-1);
    std::fstream config_file("config.cfg", std::ios::out);

    if(!config_file.is_open())
    {
        QMessageBox msgBox;
        msgBox.setText("Can not save config file");
        msgBox.exec();
        return;
    }

    config_file << N << " " << K << std::endl;
    config_file << l << " " << T << " " << 1 << std::endl;
    config_file << method << std::endl;
    this->close();
}
double HyperbolicInterface::CalculateSigma() const
{
    double N, K, l, T;
    try {
        N = stod(ui->lineEdit_N->text().toStdString());
        K = stod(ui->lineEdit_K->text().toStdString());
        l = stod(ui->lineEdit_l->text().toStdString());
        T = stod(ui->lineEdit_T->text().toStdString());
    } catch (...) {
        return 0;
    }
    double tau = T / K;
    double h = l / N;
    return tau / ( h * h);
}
void HyperbolicInterface::on_lineEdit_N_textChanged(const QString &arg1)
{
    ui->label_8->setText(std::to_string(CalculateSigma()).c_str());
}

void HyperbolicInterface::on_lineEdit_K_textChanged(const QString &arg1)
{
    ui->label_8->setText(std::to_string(CalculateSigma()).c_str());
}

void HyperbolicInterface::on_lineEdit_l_textChanged(const QString &arg1)
{
    ui->label_8->setText(std::to_string(CalculateSigma()).c_str());
}

void HyperbolicInterface::on_lineEdit_T_textChanged(const QString &arg1)
{
    ui->label_8->setText(std::to_string(CalculateSigma()).c_str());
}
