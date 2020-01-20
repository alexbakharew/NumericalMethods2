#include "solution_saver.h"
#include <fstream>
#include <iomanip>
#include<stdio.h>
bool SolutionSaver::SaveResults(const std::string &path, const std::unique_ptr<ParabHyperbSolver>& slv)
{
    remove(path.c_str());
    std::fstream output(path, std::ios::out);
    if(!output.is_open())
        return false;
    output << std::setprecision(3) << std::fixed;
    for(int i = 1; i <= slv->K - 1; ++i)
    {
        for(int j = 0; j < slv->N; ++j)
        {
            auto tmp = slv->mesh[i][j];
            output << tmp << " ";
        }
        output << std::endl;
    }
    return true;
}
