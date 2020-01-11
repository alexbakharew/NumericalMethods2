#include <iostream>
#include "parabolic_solver.h"
#include "parabolic_interface.h"
#include "hyperbolic_interface.h"
#include "solution_saver.h"
#include <QApplication>
#include <QMessageBox>
#include <QAbstractButton>
#include <QProcess>
#include <string>
#include <fstream>
#include <memory>
#include<stdio.h>

int SelectionMsgBox()// Message box for selecting type of equtation
{
    QMessageBox msgBox;
    msgBox.setText("Choose equtation type");
    msgBox.setIcon(QMessageBox::Question);
    msgBox.setWindowTitle("Lab5-6");
    msgBox.addButton("Parabolic Task", QMessageBox::YesRole);
    msgBox.addButton("Hyperbolic Task", QMessageBox::NoRole);
    return msgBox.exec();
}
int main(int argc, char* argv[])
{
    bool is_silent;// Should we launch preprocessor or launch only solver?
    if(argc == 1)
        is_silent = false;
    else if(argc == 2 && argv[1] == "--silent")
        is_silent = true;
    else
    {
        std::cout << "Undefined argument list" << std::endl;
        std::cout << "You may specify only --silent key" << std::endl;
        return -1;
    }

    const std::string config_name = "config.cfg";
    const std::string python_script = "./graphics.py";
    QApplication app(argc, argv);
    ParabolicInterface parabolic_window;
    HyperbolicInterface hyperbolic_window;

    if(SelectionMsgBox())
        hyperbolic_window.show();
    else
        parabolic_window.show();

    app.exec();// execute preprocessor

    int N, K, T;
    double l, a;
    int method;
    auto ReadDataFromConfig = [&]()
    {
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
        if(!is_silent)// We will remove config file in ui mode because user do not need this cfg file
            remove(config_name.c_str());//Otherwise, if programm launched in silent mode, config will be saved
    };

    ReadDataFromConfig();
    std::unique_ptr<BasicSolver> solver_ptr(new ParabolicSolver(N, K, l, T, a, MethodName(method)));

    solver_ptr->InitMesh();
    if(method == MethodName::Analytic)
        solver_ptr->AnalyticSolve();
    else if(method == MethodName::Explicit)
        solver_ptr->ExplicitSolve();
    else if(method == MethodName::Implicit)
        solver_ptr->ImplicitSolve();
    else if(method == MethodName::Crank_Nikolsn)
        solver_ptr->Crank_Nikolsn();
    else
    {
        std::cout << "Unsupported method name" << std::endl;
        return -1;
    }

    std::cout << "Save Results: ";
    if(SolutionSaver::SaveResults("res.txt", solver_ptr))
        std::cout << "OK" << std::endl;
    else
        std::cout << "ERROR" << std::endl;

    QProcess p;
    QStringList params;
    params << python_script.c_str();
    p.startDetached("python3", params);
    p.waitForFinished(-1);
    return 0;
}
