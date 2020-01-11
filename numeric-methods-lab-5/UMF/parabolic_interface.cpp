#include "parabolic_interface.h"
#include "ui_parabolic_interface.h"
#include <fstream>
ParabolicInterface::ParabolicInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ParabolicInterface)
{
    ui->setupUi(this);
    ui->label_6->setText(std::to_string(CalculateSigma()).c_str());
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
    config_file << l << " " << T << " " << a << std::endl;
    config_file << method << std::endl;
    this->close();
}

double ParabolicInterface::CalculateSigma() const
{
    double N, K, l, T, a;
    try {
        N = stof(ui->lineEdit->text().toStdString());
        K = stof(ui->lineEdit_2->text().toStdString());
        l = stof(ui->lineEdit_3->text().toStdString());
        T = stof(ui->lineEdit_4->text().toStdString());
        a = stof(ui->lineEdit_5->text().toStdString());
    } catch (...) {
        return 0;
    }
    auto tau = T / K;
    auto h = l / N;

    return a * a * tau / h * h;
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
