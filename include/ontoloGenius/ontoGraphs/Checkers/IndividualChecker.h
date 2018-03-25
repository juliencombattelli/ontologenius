#ifndef INDIVIDUALCHECKER_H
#define INDIVIDUALCHECKER_H

#include "ontoloGenius/ontoGraphs/Graphs/IndividualGraph.h"
#include "ontoloGenius/ontoGraphs/Checkers/ValidityChecker.h"

class IndividualChecker : public ValidityChecker<IndividualBranch_t>
{
public:
  IndividualChecker(IndividualGraph* graph) : ValidityChecker(graph) {individual_graph_ = graph;}
  ~IndividualChecker() {}

  size_t check();
private:
  IndividualGraph* individual_graph_;

  void checkSame();
  void checkReflexive();
  void checkDomain();
  void checkRange();
};

#endif