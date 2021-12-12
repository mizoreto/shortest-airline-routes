#include "algorithms.h"
#include "read_routes.h"
#include "read_airport"

using namespace std;

TEST_CASE("test the beijing has greater distance than arc", "[weight=1][part=1]") {
  routes 

  REQUIRE( tree.smallerDimVal(a, b, 0) == true );
  REQUIRE( tree.smallerDimVal(a, b, 2) == false );
  REQUIRE( tree.smallerDimVal(a, b, 1) == true );   // based on operator<
}