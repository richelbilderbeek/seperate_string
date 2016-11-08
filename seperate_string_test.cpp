#include "seperate_string.h"
#include <fstream>
#include <iostream>
#include <boost/test/unit_test.hpp>

// Boost.Test does not play well with -Weffc++
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"

void test_seperator_is_char(
  boost::function<std::vector<std::string>(const std::string&, const char)> f
)
{
  { //Single input, seperator of type char
    const std::vector<std::string> v = f("a",',');
    BOOST_CHECK(v[0]=="a");
  }
  { //Two inputs, seperator of type char
    const std::vector<std::string> v = f("a,b",',');
    BOOST_CHECK(v[0]=="a");
    BOOST_CHECK(v[1]=="b");
  }
  { //Five inputs, seperator of type char
    const std::vector<std::string> v = f("a,bb,ccc,dddd,eeeee",',');
    BOOST_CHECK(v[0]=="a");
    BOOST_CHECK(v[1]=="bb");
    BOOST_CHECK(v[2]=="ccc");
    BOOST_CHECK(v[3]=="dddd");
    BOOST_CHECK(v[4]=="eeeee");
  }
  { //Three inputs, of which one empty, seperator of type char
    const std::vector<std::string> v = f("a, ,ccc",',');
    BOOST_CHECK(v[0]=="a");
    BOOST_CHECK(v[1]==" ");
    BOOST_CHECK(v[2]=="ccc");
  }
}

void test_seperator_is_string(
  boost::function<std::vector<std::string>(const std::string&, const std::string&)> f
)
{
  { //Single input, seperator of type std::string
    const std::vector<std::string> v = f("a",",");
    BOOST_CHECK(v[0]=="a");
  }
  { //Two inputs, seperator of type std::string
    const std::vector<std::string> v = f("a,b",",");
    BOOST_CHECK(v[0]=="a");
    BOOST_CHECK(v[1]=="b");
  }
  { //Five inputs, seperator of type std::string
    const std::vector<std::string> v = f("a,bb,ccc,dddd,eeeee",",");
    BOOST_CHECK(v[0]=="a");
    BOOST_CHECK(v[1]=="bb");
    BOOST_CHECK(v[2]=="ccc");
    BOOST_CHECK(v[3]=="dddd");
    BOOST_CHECK(v[4]=="eeeee");
  }
  { //Three inputs, of which one empty, seperator of type std::string
    const std::vector<std::string> v = f("a, ,ccc",",");
    BOOST_CHECK(v[0]=="a");
    BOOST_CHECK(v[1]==" ");
    BOOST_CHECK(v[2]=="ccc");
  }
}

BOOST_AUTO_TEST_CASE(test_seperate_string)
{
  test_seperator_is_char(seperate_string1);
  test_seperator_is_char(seperate_string2);
  test_seperator_is_char(seperate_string3);
  test_seperator_is_char(seperate_string4);
  test_seperator_is_string(seperate_string5);
  test_seperator_is_string(seperate_string6);
  BOOST_CHECK_EQUAL(1 + 1, 2);
}

#pragma GCC diagnostic pop
