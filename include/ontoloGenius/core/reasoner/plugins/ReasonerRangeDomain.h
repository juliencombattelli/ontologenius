#ifndef REASONERRANGEDOMAIN_H
#define REASONERRANGEDOMAIN_H

#include "ontoloGenius/core/reasoner/plugins/ReasonerInterface.h"

class ReasonerRangeDomain : public ReasonerInterface
{
public:
  ReasonerRangeDomain() {}
  ~ReasonerRangeDomain() {}

  virtual void postReason();

  virtual std::string getName();
  virtual std::string getDesciption();

  virtual bool defaultAvtive() {return true;}
private:

  void deduceRange(IndividualBranch_t* branch, std::string& prop);
  void deduceDomain(IndividualBranch_t* branch, std::string& prop);

  void deduceObjRange(IndividualBranch_t* branch, size_t index);
  void deduceDatRange(IndividualBranch_t* branch, size_t index);
  void deduceObjDomain(IndividualBranch_t* branch, size_t index);
  void deduceDatDomain(IndividualBranch_t* branch, size_t index);
};

#endif
