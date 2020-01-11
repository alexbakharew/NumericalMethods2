#include "solution_saver.h"
#include <fstream>
#include <iomanip>
bool SolutionSaver::SaveResults(const std::string &path, const std::unique_ptr<BasicSolver>& slv)
{
    std::fstream output(path, std::ios::out);
    if(!output.is_open())
        return false;
    output << std::setprecision(3) << std::fixed;
    output << slv->N << " " << slv->K << std::endl;
    output << slv->l << " " << slv->T  << " " << slv->a << std::endl;
    for(size_t i = 0; i < slv->K; ++i)
    {
        for(size_t j = 0; j < slv->N; ++j)
        {
            auto tmp = slv->mesh[i][j];
            output << tmp << " ";
        }
        output << std::endl;
    }
    return true;
}
