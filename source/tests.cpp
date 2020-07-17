#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "shape.hpp"
#include "sphere.hpp"
#include "box.hpp"

TEST_CASE("Sphere area and volume functions", "[sphereA+V]")
{
  Sphere s0{{10.0f, 10.0f, 10.0f}, 0.0f}; // radius ist 0
  Sphere s1{{10.0f, 10.0f, 10.0f}, 10.0f}; // radius + center sind positiv (normal case)
  Sphere s2; // Standardkonstruktor, radius ist 1
  
  REQUIRE(s0.area() == 0);
  REQUIRE(s1.area() == Approx(1256.637f));
  REQUIRE(s2.area() == Approx(12.56637f));

  REQUIRE(s0.volume() == 0);
  REQUIRE(s1.volume() == Approx(4188.790f));
  REQUIRE(s2.volume() == Approx(4.18879f));
}

TEST_CASE("Box area and volume functions", "[boxA+V]")
{
  Box b0{{10.0f, 10.0f, 10.0f}, {10.0f, 10.0f, 10.0f}}; // min und max sind gleich
  Box b1{{10.0f, 10.0f, 10.0f}, {5.0f, 15.0f, 10.0f}}; // Box ist eine Ebene
  Box b2{{10.0f, 10.0f, 10.0f}, {15.0f, 15.0f, 15.0f}}; // normal case
  Box b3{{10.0f, 10.0f, 10.0f}, {5.0f, 15.0f, 15.0f}}; // a.x > b.x && a.y < b.y
  Box b4; // Standardkonstruktor {{0.0, 0.0, 0.0}{1.0, 1.0, 1.0}}

  REQUIRE(b0.area() == 0 );
  REQUIRE(b1.area() == Approx(50.0f) );
  REQUIRE(b2.area() == Approx(150.0f));
  REQUIRE(b3.area() == Approx(150.0f));
  REQUIRE(b4.area() == Approx(6.0f));

  REQUIRE(b0.volume() == 0 );
  REQUIRE(b1.volume() == 0 );
  REQUIRE(b2.volume() == Approx(125.0f));
  REQUIRE(b3.volume() == Approx(125.0f));
  REQUIRE(b4.volume() == Approx(1.0f));
}

// Vielleicht später, getter wären notwendig
/*
TEST_CASE("Correct constructors for inheritance", "[constructorInheritance]")
{
  Sphere s0({10.0f, 10.0f, 10.0f}, 5.0f, "sphäre 1", {0.2, 0.3, 0.4});

  REQUIRE()
}
*/

int main(int argc, char *argv[])
{
  Sphere sphere1{{1.0f, 1.0f, 1.0f}, 10.0f, "spherePrintedWithFunction", {0.2f, 0.3f, 0.4f}};
  Sphere sphere2{{1.0f, 1.0f, 1.0f}, 10.0f, "spherePrintedWithOperator", {0.6f, 0.7f, 0.8f}};
  sphere1.print(std::cout);
  std::cout << sphere2;

  return Catch::Session().run(argc, argv);
}
