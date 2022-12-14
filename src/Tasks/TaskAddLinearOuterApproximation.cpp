//
// Created by alireza on 12/06/22.
//

#include "TaskAddLinearOuterApproximation.h"
#include "../MIPSolver/IMIPSolver.h"
#include "../Solver/Results.h"

namespace scot {

TaskAddLinearOuterApproximation::TaskAddLinearOuterApproximation(EnvironmentPtr env) : TaskBase(env) {

}
void TaskAddLinearOuterApproximation::initialize() {

}
void TaskAddLinearOuterApproximation::execute() {

  LinearOuterApproximation lin_oa;
  for (int i = 0; i < env_->model_->getNumberOfNodes(); ++i) {
    lin_oa = env_->mip_solver_->getTotalLinearOuterApproximations().at(i);

    env_->mip_solver_->addLinearOuterApproximation(lin_oa, i);
  }
}
}