#ifndef COMPILER_H
#define COMPILER_H

#include <string>
#include <map>
#include <set>

#include "ontoloGenius/codeDescription/Code.h"
#include "ontoloGenius/Error.h"

class Compiler
{
public:
  Compiler(Code* code);
  ~Compiler(){}

  size_t compile();
  Error& getError() {return error_; }

private:
  Code* code_;
  Error error_;

  static size_t section_cpt_;

  void compileIntructions(std::map<size_t, std::string> splited);
  std::map<size_t, std::string> splitBySemicolon();
  int getIfOffset(std::string ifelse_id);

  void onVariableInstruction(std::string variable, std::string instruction, size_t pose);
  void onOntologyInstruction(std::string instruction, size_t pose);

  void getParameters(std::string arg, size_t pose, std::vector<std::string>& args, std::vector<size_t>& args_pose);
  //int splitIfBlock(std::map<size_t, std::string>& splited, std::string ifelse_id);
};

#endif