
#include <catch.hpp>
#include <sstream>
#include "scoped_ptr.hpp"

TEST_CASE("Get and *")
{
  scoped_ptr<int> p1(new int(4));
  int * ptr = p1.get();
  scoped_ptr<int> p2(new int(2));
  int k = *p2;

  REQUIRE( *ptr == 4 );
  REQUIRE( k == 2 );
}

TEST_CASE("Swap")
{
  scoped_ptr<int> p1(new int(4));
  scoped_ptr<int> p2(new int(2));
  p1.swap(p2);
  int * ptr = p1.get();
  int k = *p2;

  REQUIRE( *ptr == 2 );
  REQUIRE( k == 4 );
}

TEST_CASE("Reset")
{
  scoped_ptr<int> p1(new int(4));
  p1.reset(new int(5));
  int k = *p1;
  REQUIRE( k == 5 );
}

TEST_CASE("->")
{
  scoped_ptr<X> z(new X);
  z->m = 3;
  int k = z->m;
  REQUIRE( k == 3 );
}
