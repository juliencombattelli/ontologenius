#include "ros/ros.h"
#include <gtest/gtest.h>
#include <sstream>

#include "ontoloGenius/utility/OntologyManipulator.h"

OntologyManipulator* onto_ptr;

TEST(requests_tests, getName_call)
{
  std::string res;
  std::string test_word = "human";
  bool res_bool = true;

  for(size_t i = 0; i < 1000; i++)
  {
    res = onto_ptr->classes.getName(test_word);
    res_bool = res_bool && (res == "human");
  }

  EXPECT_TRUE(res_bool);
}

TEST(requests_tests, find_call)
{
  std::vector<std::string> res;
  std::string test_word = "human";
  bool res_bool = true;

  for(size_t i = 0; i < 1000; i++)
  {
    res = onto_ptr->classes.find(test_word);
    res_bool = res_bool && ((res.size() == 1) && (res[0] == "human"));
  }

  EXPECT_TRUE(res_bool);
}

TEST(requests_tests, getUp_call)
{
  std::vector<std::string> res;
  std::string test_word = "human";
  bool res_bool = true;

  for(size_t i = 0; i < 1000; i++)
  {
    res = onto_ptr->classes.getUp(test_word);
    res_bool = res_bool && ((res.size() == 8) &&
                            (find(res.begin(), res.end(), "entity") != res.end()) &&
                            (find(res.begin(), res.end(), "animate") != res.end()) &&
                            (find(res.begin(), res.end(), "activity") != res.end()) &&
                            (find(res.begin(), res.end(), "attribute") != res.end()) &&
                            (find(res.begin(), res.end(), "human") != res.end()) &&
                            (find(res.begin(), res.end(), "agent") != res.end()) &&
                            (find(res.begin(), res.end(), "vitality") != res.end()) &&
                            (find(res.begin(), res.end(), "living") != res.end()));
  }

  EXPECT_TRUE(res_bool);
}

TEST(requests_tests, getDown_call)
{
  std::vector<std::string> res;
  std::string test_word = "human";
  bool res_bool = true;

  for(size_t i = 0; i < 1000; i++)
  {
    res = onto_ptr->classes.getDown(test_word);
    res_bool = res_bool && ((res.size() == 4) &&
                            (find(res.begin(), res.end(), "human") != res.end()) &&
                            (find(res.begin(), res.end(), "woman") != res.end()) &&
                            (find(res.begin(), res.end(), "man") != res.end()) &&
                            (find(res.begin(), res.end(), "child") != res.end()));
  }

  EXPECT_TRUE(res_bool);
}

TEST(requests_tests, getDisjoint_call)
{
  std::vector<std::string> res;
  std::string test_word = "human";
  bool res_bool = true;

  for(size_t i = 0; i < 1000; i++)
  {
    res = onto_ptr->classes.getDisjoint(test_word);
    res_bool = res_bool && ((res.size() == 8) &&
                            (find(res.begin(), res.end(), "fish") != res.end()) &&
                            (find(res.begin(), res.end(), "redFish") != res.end()) &&
                            (find(res.begin(), res.end(), "dog") != res.end()) &&
                            (find(res.begin(), res.end(), "cat") != res.end()) &&
                            (find(res.begin(), res.end(), "animal") != res.end()) &&
                            (find(res.begin(), res.end(), "robot") != res.end()) &&
                            (find(res.begin(), res.end(), "pepper") != res.end()) &&
                            (find(res.begin(), res.end(), "pr2") != res.end()));
  }

  EXPECT_TRUE(res_bool);
}

TEST(requests_tests, depth_call)
{
  std::vector<std::string> res;
  std::string test_word = "human";
  bool res_bool = true;

  for(size_t i = 0; i < 1000; i++)
  {
    res = onto_ptr->classes.getUp(test_word, 1);
    res_bool = res_bool && ((res.size() == 3) &&
                            (find(res.begin(), res.end(), "human") != res.end()) &&
                            (find(res.begin(), res.end(), "agent") != res.end()) &&
                            (find(res.begin(), res.end(), "living") != res.end()));
  }

  EXPECT_TRUE(res_bool);
}

TEST(requests_tests, select_true_call)
{
  std::string test_word = "human";
  bool res_bool = true;

  for(size_t i = 0; i < 1000; i++)
  {
    res_bool = res_bool && onto_ptr->classes.isA(test_word, "entity");
  }

  EXPECT_TRUE(res_bool);
}

TEST(requests_tests, select_false_call)
{
  std::vector<std::string> res;
  std::string test_word = "human";
  bool res_bool = true;

  for(size_t i = 0; i < 1000; i++)
  {
    res_bool = res_bool && (!onto_ptr->classes.isA(test_word, "animal"));
  }

  EXPECT_TRUE(res_bool);
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "ontologenius_requests_tester");

  ros::NodeHandle n;
  OntologyManipulator onto(&n);
  onto_ptr = &onto;

  onto.close();

  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();

  return 0;
}