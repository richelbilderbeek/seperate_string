#include "seperate_string.h"
#include <fstream>
#include <iostream>
#include <boost/test/unit_test.hpp>

// Boost.Test does not play well with -Weffc++
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"


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
