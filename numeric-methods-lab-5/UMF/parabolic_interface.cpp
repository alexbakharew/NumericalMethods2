#include "parabolic_interface.h"
#include "ui_parabolic_interface.h"
#include <fstream>
ParabolicInterface::ParabolicInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ParabolicInterface)
{
    ui->setupUi(this);
    ui->label_6->setText(std::to_string(CalculateSigma()).c_str());
    ui->lineEdit_6->setDisabled(1);
    ui->lineEdit_6->setText("0");
}

ParabolicInterface::~ParabolicInterface()
{
    delete ui;
}

void ParabolicInterface::on_pushButton_clicked()
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
    a = ui->lineEdit_5->text().toStdString();
    teta = ui->lineEdit_6->text().toStdString();
    if(ui->radioButton_4->isChecked())
    {
        method = MethodName::Analytic;
    }
    else if(ui->radioButton->isChecked())
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
    config_file << l << " " << T << " " << a << " " << teta << std::endl;
    config_file << method << std::endl;
    this->close();
}

double ParabolicInterface::CalculateSigma() const
{
    double N, K, l, T, a;
    try {
        N = stod(ui->lineEdit->text().toStdString());
        K = stod(ui->lineEdit_2->text().toStdString());
        l = stod(ui->lineEdit_3->text().toStdString());
        T = stod(ui->lineEdit_4->text().toStdString());
        a = stod(ui->lineEdit_5->text().toStdString());
    } catch (...) {
        return 0;
    }
    double tau = T / K;
    double h = l / N;
    return (a * a * tau) / ( h * h);
}
void ParabolicInterface::on_lineEdit_textEdited(const QString &arg1)
{
    ui->label_6->setText(std::to_string(CalculateSigma()).c_str());
}

void ParabolicInterface::on_lineEdit_2_textChanged(const QString &arg1)
{
    ui->label_6->setText(std::to_string(CalculateSigma()).c_str());
}

void ParabolicInterface::on_lineEdit_3_textChanged(const QString &arg1)
{
    ui->label_6->setText(std::to_string(CalculateSigma()).c_str());
}

void ParabolicInterface::on_lineEdit_4_textChanged(const QString &arg1)
{
    ui->label_6->setText(std::to_string(CalculateSigma()).c_str());
}

void ParabolicInterface::on_lineEdit_5_textChanged(const QString &arg1)
{
    ui->label_6->setText(std::to_string(CalculateSigma()).c_str());
}

void ParabolicInterface::on_radioButton_4_clicked()
{
    ui->lineEdit_6->setDisabled(1);
    ui->lineEdit_6->setText("0");
}

void ParabolicInterface::on_radioButton_clicked()
{
    ui->lineEdit_6->setDisabled(1);
    ui->lineEdit_6->setText("0");
}

void ParabolicInterface::on_radioButton_2_clicked()
{
    ui->lineEdit_6->setDisabled(1);
    ui->lineEdit_6->setText("1");
}

void ParabolicInterface::on_radioButton_3_clicked()
{
    ui->lineEdit_6->setEnabled(1);
    ui->lineEdit_6->setText("0.5");
}
