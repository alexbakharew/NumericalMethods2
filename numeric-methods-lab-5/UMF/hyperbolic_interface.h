#ifndef HYPERBOLIC_INTERFACE_H
#define HYPERBOLIC_INTERFACE_H

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

private:
    Ui::HyperbolicInterface *ui;
};

#endif // HYPERBOLIC_INTERFACE_H
