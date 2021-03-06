add_executable(example example.cpp)

target_link_libraries(example ${FRAMEWORK_NAME} ${LIBRARIES})
add_dependencies(example glfw ${FRAMEWORK_NAME} ${COPY_BINARY})

install(TARGETS example DESTINATION .)

add_executable(raytracer raytracer.cpp)

target_link_libraries(raytracer ${FRAMEWORK_NAME} ${LIBRARIES}
  glfw
  ${GLFW_LIBRARIES}
  )
add_dependencies(raytracer glfw ${FRAMEWORK_NAME} ${COPY_BINARY})

install(TARGETS raytracer DESTINATION .)

# Build tests
add_executable(tests
  tests.cpp
  ../framework/shape.cpp
  ../framework/sphere.cpp
  ../framework/box.cpp
  ../framework/color.hpp
  ../framework/ray.hpp
  ../framework/hitpoint.hpp
  )
target_link_libraries(tests
  ${GLFW_LIBRARIES}
  )

# sdf_parser_sample
add_executable(sdf_parser_sample sdf_parser_sample.cpp)

target_link_libraries(sdf_parser_sample ${FRAMEWORK_NAME} ${LIBRARIES}
  glfw
  ${GLFW_LIBRARIES}
  )
add_dependencies(sdf_parser_sample glfw ${FRAMEWORK_NAME} ${COPY_BINARY})

install(TARGETS sdf_parser_sample DESTINATION .)