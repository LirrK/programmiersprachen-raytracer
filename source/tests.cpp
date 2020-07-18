#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
#include "shape.hpp"
#include "sphere.hpp"
#include "box.hpp"
#include "ray.hpp"

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
/*
TEST_CASE("intersect_ray_sphere", "[intersect]")
{
  // Ray
  glm::vec3 ray_origin{0.0f, 0.0f, 0.0f};
  glm::vec3 ray_direction{0.0f, 0.0f, 1.0f};
  Ray ray{ray_origin, ray_direction};

  // Sphere
  glm::vec3 sphere_center{0.0f, 0.0f, 5.0f};
  float sphere_radius{1.0f};
  Sphere sphere{sphere_center, sphere_radius};

  float distance = 0.0f;
  auto result = glm::intersectRaySphere(
    ray.origin, ray.direction,
    sphere_center,
    sphere_radius * sphere_radius, //squared radius !!!
    distance);
  
  REQUIRE(distance == Approx(4.0f));
}
*/
int main(int argc, char *argv[])
{
  Sphere sphere1{{1.0f, 1.0f, 1.0f}, 10.0f, "spherePrintedWithFunction", {0.2f, 0.3f, 0.4f}};
  Sphere sphere2{{2.0f, 2.0f, 2.0f}, 20.0f, "spherePrintedWithOperator", {0.6f, 0.7f, 0.8f}};
  Box box1{{1.0f, 1.0f, 1.0f}, {2.0f, 2.0f, 2.0f}, "boxPrintedWithFunction", {0.2f, 0.3f, 0.4f}};
  Box box2{{5.0f, 5.0f, 5.0f}, {6.0f, 6.0f, 6.0f}, "boxPrintedWithOperator", {0.6f, 0.7f, 0.8f}};

  sphere1.print(std::cout);
    std::cout << std::endl;
  std::cout << sphere2;
    std::cout << std::endl;
  box1.print(std::cout);
    std::cout << std::endl;
  std::cout << box2;
    std::cout << std::endl;


  return Catch::Session().run(argc, argv);
}
