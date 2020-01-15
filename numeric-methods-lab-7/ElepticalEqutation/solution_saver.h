#ifndef SOLUTION_SAVER_H
#define SOLUTION_SAVER_H
#include "eleptical_solver.h"
#include <fstream>
class SolutionSaver
{
public:
    SolutionSaver(){}
    ~SolutionSaver(){}
    static bool SaveResults(const ElepticalSolver& slv, const std::string& path)
    {
        std::fstream result(path, std::ios::out);
        if(!result.is_open())
            return false;
        for(int i = 0; i < slv.N1; ++i)
        {
            std::string line;
            for(int j = 0; j < slv.N2; ++j)
            {
                line += std::to_string(slv.mesh[i][j]) + " ";
            }
            result << line << std::endl;
        }
        return true;
    }
};
#endif // SOLUTION_SAVER_H
