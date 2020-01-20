#ifndef SOLUTIONSAVER_H
#define SOLUTIONSAVER_H
#include <string>
#include <memory>
#include "parab_hyperb_solver.h"
class SolutionSaver
{
public:
    SolutionSaver(){}
    static bool SaveResults(const std::string &path, const std::unique_ptr<ParabHyperbSolver>& slv);
};

#endif // SOLUTIONSAVER_H
