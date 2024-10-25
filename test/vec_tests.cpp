#include "gtest/gtest.h"
#include "../src/vec.h"

/**
 * @brief Test class for vector operations
 *
 * This class sets up test cases for the _vec3
 * class operations using the Google Test framework
 */

class vecTestClass : public ::testing::Test {

protected:
 /**
  * @brief Constructor initializes the test vectors
  */

 vecTestClass() : a{0,1,2}, b{0,0,1} { }
 /**
  * @brief Destructor for cleanup
  */

 ~vecTestClass() override { /* nothing to do */ }

 /**
  * @brief Setup before each test case, test vector addition and subtraction
  */

 void SetUp() override {

  double3 c = a+b; ///< test addition
  add_matches = true; ///< set default

  for (int i=0;i<3;i++)
   if (c[i] != a[i] + b[i])
    add_matches=false; ///< Invalidate if component doesn't match

  //! test subtraction
  double3 d = a-b;
  sub_matches = true; /// Set default

  for (int i=0;i<3;i++)
   if (d[i] != a[i] - b[i])
    sub_matches=false;
 }

 /**
  * @brief Tear down after each test case
  */

 void TearDown() override {
  /* optional code to call after each test prior to destructor */
 }
 double3 a, b; ///< class data
 bool sub_matches = false;
 bool add_matches = false;
};

/**
 * @brief Test case for vector addition
 */

TEST_F(vecTestClass, VecAdd) { // makes a VecTestClass, checks value of add_matches
 EXPECT_EQ(add_matches, true);
}

/**
 * @brief Test case for vector subtraction
 */

TEST_F(vecTestClass, VecSub) {
 EXPECT_EQ(sub_matches, true);
}

