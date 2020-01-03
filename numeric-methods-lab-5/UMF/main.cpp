#include <iostream>
#include "solver.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    int N, K, T;
    std::cin >> N >> K;

    double l;
    std::cin >> l >> T;
    //10 10 3.14159 10


    Solver slv(N, K, l, T);
    slv.InitMesh();
    slv.ExplicitSolve();
    if(SolutionSaver::SaveResults("res.txt", slv))
        std::cout << "OK" << std::endl;
    else
        std::cout << "ERROR" << std::endl;

//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    a.exec();
//    std::cout << "here" << std::endl;
}
