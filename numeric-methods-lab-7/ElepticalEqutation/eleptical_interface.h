#ifndef ELEPTICAL_INTERFACE_H
#define ELEPTICAL_INTERFACE_H

#include <QMainWindow>

namespace Ui {
class ElepticalInterface;
}

class ElepticalInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit ElepticalInterface(QWidget *parent = nullptr);
    ~ElepticalInterface();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ElepticalInterface *ui;
};

#endif // ELEPTICAL_INTERFACE_H
