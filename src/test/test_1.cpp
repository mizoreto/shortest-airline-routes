TEST_CASE("airport with no flights", "[weight=1][part=1]") {
  

  REQUIRE( tree.smallerDimVal(a, b, 0) == true );
  REQUIRE( tree.smallerDimVal(a, b, 2) == false );
  REQUIRE( tree.smallerDimVal(a, b, 1) == true );   // based on operator<
}