cmake_minimum_required(VERSION 3.14)
project(progvar-library)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)
include_directories(../pvl)

enable_testing()

include_directories(graph)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)

add_executable(BaseGraph graph/unwieghted_graphs.cc)
target_link_libraries(BaseGraph gtest_main)
gtest_discover_tests(BaseGraph)

add_executable(Dijkstra graph/shortest_paths/dijkstra.cc)
target_link_libraries(Dijkstra gtest_main)
gtest_discover_tests(Dijkstra)

add_executable(FloydWarshall graph/shortest_paths/floyd_warshall.cc)
target_link_libraries(FloydWarshall gtest_main)
gtest_discover_tests(FloydWarshall)
