#include "eleptical_interface.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ElepticalInterface w;
    w.show();

    return a.exec();
}
