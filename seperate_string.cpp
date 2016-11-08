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
  const char seperator
)
{
  std::vector<std::string> v;
  boost::algorithm::split(v,input,
    std::bind2nd(std::equal_to<char>(),seperator),
    boost::algorithm::token_compress_on);
  return v;
}

std::vector<std::string> seperate_string2(
  const std::string& input,
  const char seperator
)
{
  std::istringstream is(input);
  std::vector<std::string> v;
  for (
    std::string sub;
    std::getline(is, sub, seperator);
    v.push_back(sub)) {} //!OCLINT indeed an empty for loop
  return v;
}

std::vector<std::string> seperate_string3(
  const std::string& input,
  const char seperator
)
{
  std::vector<std::string> v;
  typedef std::string::const_iterator Iterator;
  const Iterator end = input.end();
  Iterator i1 = input.begin();
  {
    //Copy until first comma
    Iterator i2 = std::find(i1,end,seperator);
    assert(i1!=i2);
    std::string s;
    std::copy(i1,i2,std::back_inserter(s));
    v.push_back(s);
    i1 = i2;
  }
  while (i1!=end)
  {
    //Copy from comma to (comma || end)
    Iterator i2 = std::find(i1 + 1,end,seperator);
    assert(i1!=i2);
    assert(i2 == end || *i2 == seperator);
    std::string s;
    std::copy(i1+1,i2,std::back_inserter(s));
    v.push_back(s);
    i1 = i2;
  }
  return v;
}

std::vector<std::string> seperate_string4(
  std::string input,
  const char seperator
)
{
  assert(!input.empty());
  assert(input[0]!=seperator);
  assert(input[input.size()-1]!=seperator);

  std::vector<std::string> result;
  int pos = 0;
  while(pos<static_cast<int>(input.size()))
  {
    if (input[pos]==seperator)
    {
      const std::string found = input.substr(0,pos);
      result.push_back(found);
      input = input.substr(pos+1,input.size()-pos);
      pos = 0;
    }
    ++pos;
  }
  result.push_back(input);
  return result;
}

std::vector<std::string> seperate_string5(
  const std::string& input,
  const std::string& seperator
)
{
  std::vector<std::string> v;
  typedef std::string::const_iterator Iterator;
  const Iterator end = input.end();
  Iterator i1 = input.begin();
  {
    //Copy until first comma
    Iterator i2 = std::search(i1,end,seperator.begin(), seperator.end());
    assert(i1!=i2);
    std::string s;
    std::copy(i1,i2,std::back_inserter(s));
    v.push_back(s);
    i1 = i2;
  }
  while (i1!=end)
  {
    //Copy from comma to (comma || end)
    Iterator i2 = std::search(i1 + 1,end,seperator.begin(), seperator.end());
    assert(i1!=i2);
    assert(i2 == end || std::equal(seperator.begin(),seperator.end(),i2));
    std::string s;
    std::copy(i1+1,i2,std::back_inserter(s));
    v.push_back(s);
    i1 = i2;
  }
  return v;
}

std::vector<std::string> seperate_string6(
  std::string input,
  const std::string& seperator
)
{
  assert(input.empty()==false);
  assert(input.substr(0,seperator.size()) != seperator);
  assert(input.substr(input.size()-seperator.size(),seperator.size())!=seperator);
  std::vector<std::string> result;
  int pos = 0;
  while(pos<static_cast<int>(input.size()))
  {
    if (input.substr(pos,seperator.size())==seperator)
    {
      const std::string found = input.substr(0,pos);
      result.push_back(found);
      input = input.substr(pos+seperator.size(),input.size()-pos);
      pos = 0;
    }
    ++pos;
  }
  result.push_back(input);
  return result;
}

