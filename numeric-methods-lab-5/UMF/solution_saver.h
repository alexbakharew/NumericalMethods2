#ifndef SOLUTIONSAVER_H
#define SOLUTIONSAVER_H
#include <string>
#include <memory>
#include "basic_solver.h"
class SolutionSaver
{
public:
    SolutionSaver(){}
    static bool SaveResults(const std::string &path, const std::unique_ptr<BasicSolver>& slv);
};

#endif // SOLUTIONSAVER_H
