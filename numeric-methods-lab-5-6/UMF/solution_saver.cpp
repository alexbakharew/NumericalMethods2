#include "solution_saver.h"
#include <fstream>
#include <iomanip>
#include<stdio.h>
bool SolutionSaver::SaveResults(const std::string &path, const std::unique_ptr<BasicSolver>& slv)
{
    remove(path.c_str());
    std::fstream output(path, std::ios::out);
    if(!output.is_open())
        return false;
    output << std::setprecision(3) << std::fixed;
    for(int i = slv->K - 1; i >= 0; --i)
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
