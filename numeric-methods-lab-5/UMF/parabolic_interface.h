#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "methods.h"
#include <QMainWindow>
#include <QMessageBox>
#include <string>
namespace Ui {
class ParabolicInterface;
}

class ParabolicInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit ParabolicInterface(QWidget *parent = nullptr);
    ~ParabolicInterface();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_textEdited(const QString &arg1);

    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_lineEdit_4_textChanged(const QString &arg1);

    void on_lineEdit_5_textChanged(const QString &arg1);

    void on_radioButton_4_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

private:
    double CalculateSigma() const;
    std::string N, K, T;
    std::string l, a, teta;
    MethodName method;
    Ui::ParabolicInterface* ui;
};

#endif // MAINWINDOW_H
