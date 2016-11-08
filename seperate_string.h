#ifndef SEPERATE_STRING_H
#define SEPERATE_STRING_H

#include <algorithm>
#include <cassert>
#include <sstream>
#include <string>
#include <vector>

#include <string>
#include <vector>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#include <boost/algorithm/string/split.hpp>
#include <boost/function.hpp>
#pragma GCC diagnostic pop

std::vector<std::string> seperate_string1(
  const std::string& input,
  const char seperator);

std::vector<std::string> seperate_string2(
  const std::string& input,
  const char seperator);

std::vector<std::string> seperate_string3(
  const std::string& input,
  const char seperator
);


std::vector<std::string> seperate_string4(
  std::string input,
  const char seperator
);

std::vector<std::string> seperate_string5(
  const std::string& input,
  const std::string& seperator);

std::vector<std::string> seperate_string6(
  std::string input,
  const std::string& seperator
);

void test_seperator_is_char(
  boost::function<std::vector<std::string>(const std::string&, const char)> f
);

void test_seperator_is_string(
  boost::function<std::vector<std::string>(const std::string&, const std::string&)> f
);

#endif //~SEPERATE_STRING_H
