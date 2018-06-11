cmake_minimum_required(VERSION 2.8.3)
project(exotica_valkyrie_collision_checking_example)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  exotica
  exotica_examples
)

catkin_package(
    CATKIN_DEPENDS exotica exotica_python exotica_examples val_description
)

include_directories(${catkin_INCLUDE_DIRS})
add_executable(${PROJECT_NAME}_node src/cpp_example.cpp)
set_target_properties(${PROJECT_NAME}_node PROPERTIES OUTPUT_NAME cpp_example PREFIX "")
target_link_libraries(${PROJECT_NAME}_node ${catkin_LIBRARIES})

install(PROGRAMS
  scripts/python_example
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

## Mark executables and/or libraries for installation
install(TARGETS ${PROJECT_NAME}_node
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
