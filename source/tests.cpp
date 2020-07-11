#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "shape.hpp"
#include "sphere.hpp"

TEST_CASE("Sphere area and volume functions", "[sphereA+V]")
{
  Sphere s0{{10.0f, 10.0f, 10.0f}, 0.0f}; // radius ist 0
  Sphere s1{{10.0f, 10.0f, 10.0f}, 10.0f}; // radius + center sind positiv
  Sphere s2; // Standardkonstruktor, radius ist 1
  
  REQUIRE(s0.area() == 0);
  REQUIRE(s1.area() == Approx(1256.637f));
  REQUIRE(s2.area() == Approx(12.56637f));

  REQUIRE(s0.volume() == 0);
  REQUIRE(s1.volume() == Approx(4188.790f));
  REQUIRE(s2.volume() == Approx(4.18879f));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
