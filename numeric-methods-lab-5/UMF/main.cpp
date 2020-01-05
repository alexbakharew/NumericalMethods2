#include <iostream>
#include "parabolic_solver.h"
#include "mainwindow.h"
#include <QApplication>
#include <QProcess>
#include <string>
#include <fstream>
int main(int argc, char* argv[])
{

    const std::string config_name = "config.cfg";

    QApplication app(argc, argv);
    MainWindow w;
    w.show();
    app.exec();

    int N, K, T;
    double l, a;
    int method;
    std::fstream config_file(config_name, std::ios::in);
    try
    {
        config_file >> N >> K;
        config_file >> l >> T >> a;
        config_file >> method;
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return -1;
    }

    Solver slv(N, K, l, T, a, MethodName(method));
    slv.InitMesh();
    if(method == MethodName::Analytic)
        slv.AnalyticSolve();
    else if(method == MethodName::Explicit)
        slv.ExplicitSolve();
    else if(method == MethodName::Implicit)
        slv.ImplicitSolve();
    else if(method == MethodName::Crank_Nikolsn)
        slv.Crank_Nikolsn();
    else
    {
        std::cout << "Unsupported method name" << std::endl;
        return -1;
    }

    std::cout << "Save Results: ";
    if(SolutionSaver::SaveResults("res.txt", slv))
        std::cout << "OK" << std::endl;
    else
        std::cout << "ERROR" << std::endl;

    QProcess p;
    QStringList params;
    params << "graphics.py";
    p.startDetached("python3", params);
    p.waitForFinished(-1);
    return 0;
}
