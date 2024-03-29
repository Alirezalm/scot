//
// Created by alireza on 02/06/22.
//

#include "Iteration.h"
#include "Logger.h"
#include "Results.h"

namespace Scot {
Iteration::Iteration(EnvironmentPtr env) {
  env_ = env;
  iteration_number_ = env_->Results->getNumberOfIterations() + 1;

  if (iteration_number_ != 1) {

    total_number_of_cuts_ =
        env_->Results->Iterations.back()->total_number_of_cuts_;
    number_first_order_oa_cuts_ =
        env->Results->Iterations.back()->number_first_order_oa_cuts_;

    number_second_order_oa_cuts_ =
        env->Results->Iterations.back()->number_second_order_oa_cuts_;
    number_ecp_cuts_ = env->Results->Iterations.back()->number_ecp_cuts_;
  }

  env_->Logger->logDebug("new iteration created.", env_->Model->getRank());
  iteration_time_ = 1e-3; // todo: need revise
}
} // namespace Scot
