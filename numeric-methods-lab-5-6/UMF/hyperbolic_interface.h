#ifndef HYPERBOLIC_INTERFACE_H
#define HYPERBOLIC_INTERFACE_H
#include "methods.h"
#include <QMainWindow>

namespace Ui {
class HyperbolicInterface;
}

class HyperbolicInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit HyperbolicInterface(QWidget *parent = nullptr);
    ~HyperbolicInterface();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_N_textChanged(const QString &arg1);

    void on_lineEdit_K_textChanged(const QString &arg1);

    void on_lineEdit_l_textChanged(const QString &arg1);

    void on_lineEdit_T_textChanged(const QString &arg1);

    void on_lineEdit_a_textChanged(const QString &arg1);

private:
    double CalculateSigma() const;
    std::string N, K, T;
    std::string l, a;
    MethodName method;
    Ui::HyperbolicInterface *ui;
};

#endif // HYPERBOLIC_INTERFACE_H
