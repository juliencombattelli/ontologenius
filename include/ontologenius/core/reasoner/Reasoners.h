#ifndef ONTOLOGENIUS_REASONERS_H
#define ONTOLOGENIUS_REASONERS_H

#include <map>
#include <string>

#include <pluginlib/class_loader.h>

#include "ontologenius/core/ontoGraphs/Ontology.h"
#include "ontologenius/core/reasoner/ConfigReader.h"
#include "ontologenius/core/reasoner/plugins/ReasonerInterface.h"

namespace ontologenius {

class Reasoners
{
public:
  Reasoners(Ontology* onto = nullptr);
  ~Reasoners();

  void link(Ontology* onto);

  void configure(const std::string& config_path);
  void load();
  std::string list();
  std::vector<std::string> listVector();
  std::vector<std::string> activeListVector();

  int activate(const std::string& plugin);
  int deactivate(const std::string& plugin);
  std::string getDescription(std::string& plugin);

  void runPreReasoners();
  void runPostReasoners();
  void runPeriodicReasoners();

  std::vector<std::string> getNotifications()
  {
    auto tmp = std::move(notifications_);
    notifications_.clear();
    return tmp;
  }

  std::vector<std::pair<std::string, std::string>> getExplanations()
  {
    auto tmp = std::move(explanations_);
    explanations_.clear();
    return tmp;
  }

private:
  Ontology* ontology_;
  ConfigReader config_;
  std::map<std::string, ReasonerInterface*> reasoners_;
  std::map<std::string, ReasonerInterface*> active_reasoners_;
  std::vector<std::string> notifications_;
  // Here the explanations are about relations added through FOL
  std::vector<std::pair<std::string, std::string>> explanations_;

  pluginlib::ClassLoader<ReasonerInterface> loader_;

  void applyConfig();

  void computeIndividualsUpdates();
  void computeIndividualsUpdatesPeriodic();
  void resetIndividualsUpdates();
};

} // namespace ontologenius

#endif // ONTOLOGENIUS_REASONERS_H
