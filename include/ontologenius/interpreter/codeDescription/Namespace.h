#ifndef ONTOLOGENIUS_NAMESPACE_H
#define ONTOLOGENIUS_NAMESPACE_H

#include <string>

namespace ontologenius {

class Namespace
{
public:
  Namespace(std::string name);
  ~Namespace() {}

  bool isThisNamespace(std::string ns);
  std::string ns() {return name_; }

private:
  std::string name_;
};

} // namespace ontologenius

#endif // ONTOLOGENIUS_NAMESPACE_H
