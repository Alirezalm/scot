//
// Created by alireza on 30/05/22.
//

#ifndef SCOT_SRC_SOLVER_SCOTSOLVER_H_
#define SCOT_SRC_SOLVER_SCOTSOLVER_H_

#include "../Algorithm/IAlgorithm.h"
#include "Enums.h"
#include "Environment.h"
#include "filesystem"

namespace Scot {
/**
 * @brief SCOT solver main API
 */
class ScotSolver {
public:
  /**
   * @brief default constructor
   */
  explicit ScotSolver();

  ~ScotSolver() = default;

  void outputHeader();

  bool setProblemData(std::filesystem::path &inputPath);

  bool setNumberOfNonzeros(int nzeros);

  bool setObjective();

  bool setSparseConstraints();

  bool setMpi();

  void setTotalNodes(int totalNodes);

  void setRank(int rank);

  bool solve();

  EnvironmentPtr getEnvironment();

private:
  // select an appropriate algorithm based on use defined setting
  void selectAlgorithm();

  void saveResults(VectorDouble &x);
  // data members
  EnvironmentPtr Env; // solver environment
  IAlgorithmPtr SolutionAlgorithm;
  int NumberOfNonzeros;
  int TotalNodes; // total number of MPI nodes
  int Rank;       // MPI rank
  double Upperbound;
  VectorDouble Response;
  VectorDouble2D Samples;
  ProbType ProblemType;
  std::string Ptype;
  void sparsify(VectorDouble &x) const;
};
} // namespace Scot

#endif // SCOT_SRC_SOLVER_SCOTSOLVER_H_
