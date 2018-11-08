#include "ontoloGenius/utility/OntologyClient.h"

std::vector<std::string> OntologyClient::getUp(std::string& name, int depth, const std::string& selector)
{
  ontologenius::OntologeniusService srv;
  if(selector == "")
  {
    srv.request.action = "getUp";
    srv.request.param = name;
  }
  else
  {
    srv.request.action = "select:getUp";
    srv.request.param = selector + "=" + name;
  }

  if(depth >= 0)
    srv.request.param += " < " + std::to_string(depth);

  return call(srv);
}

bool OntologyClient::isA(std::string& name, const std::string& base_class)
{
  std::vector<std::string> res = getUp(name, -1, base_class);
  if(res.size() == 0)
    return false;
  else
    return true;
}

std::string OntologyClient::getName(const std::string& name)
{
  ontologenius::OntologeniusService srv;
  srv.request.action = "getName";
  srv.request.param = name;

  return callStr(srv);
}

std::vector<std::string> OntologyClient::find(const std::string& name)
{
  ontologenius::OntologeniusService srv;

  srv.request.action = "find";
  srv.request.param = name;

  return call(srv);
}