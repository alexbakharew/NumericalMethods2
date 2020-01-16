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

    int eq_type;
    if(SelectionMsgBox())
    {
        eq_type = 2;
        hyperbolic_window.show();
    }
    else
    {
        eq_type = 1;
        parabolic_window.show();
    }


    app.exec();// execute preprocessor

    int N, K, T;
    double l, a, teta;
    int method;
    auto ReadDataFromConfig = [&]()
    {
        std::fstream config_file(config_name, std::ios::in);
        try
        {
            config_file >> N >> K;
            config_file >> l >> T >> a >> teta;
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
    std::unique_ptr<BasicSolver> solver_ptr(new ParabolicSolver(N, K, l, T, a, MethodName(method), teta));

    solver_ptr->InitMesh();
    std::string method_name;
    if(method == MethodName::Analytic)
    {
        solver_ptr->AnalyticSolve();
        method_name = "Analytic";
    }
    else if(method == MethodName::Explicit)
    {
        solver_ptr->ExplicitSolve();
        method_name = "Explicit";
    }
    else if(method == MethodName::Implicit)
    {
       solver_ptr->ImplicitSolve();
       method_name = "Implicit";
    }
    else if(method == MethodName::Crank_Nikolsn)
    {
        solver_ptr->Crank_Nikolsn();
        method_name = "Crank_Nikolsn";
    }

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
    params << python_script.c_str() << std::to_string(eq_type).c_str() << std::to_string(N).c_str() << std::to_string(K).c_str() << std::to_string(l).c_str() <<
              std::to_string(T).c_str() << std::to_string(a).c_str() << method_name.c_str();

    p.startDetached("python3", params);
    p.waitForFinished(-1);
    return 0;
}
