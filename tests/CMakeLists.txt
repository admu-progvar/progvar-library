cmake_minimum_required(VERSION 3.14)
project(progvar-library)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)
include_directories(../pvl)

enable_testing()

include_directories(graphs)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)

add_executable(BaseGraph graphs/unwieghted_graphs.cc)
target_link_libraries(BaseGraph gtest_main)
gtest_discover_tests(BaseGraph)

add_executable(Dijkstra graphs/shortest_paths/dijkstra.cc)
target_link_libraries(Dijkstra gtest_main)
gtest_discover_tests(Dijkstra)

add_executable(FloydWarshall graphs/shortest_paths/floyd_warshall.cc)
target_link_libraries(FloydWarshall gtest_main)
gtest_discover_tests(FloydWarshall)

add_executable(MaxFlow graphs/max_flow/max_flow.cc)
target_link_libraries(MaxFlow gtest_main)
gtest_discover_tests(MaxFlow)

add_executable(Tree graphs/tree.cc)
target_link_libraries(Tree gtest_main)
gtest_discover_tests(Tree)

add_executable(Prim graphs/mst/prim.cc)
target_link_libraries(Prim gtest_main)
gtest_discover_tests(Prim)

add_executable(ZAlgo strings/z.cc)
target_link_libraries(ZAlgo gtest_main)
gtest_discover_tests(ZAlgo)

add_executable(PrimeSieve math/numtheory/prime_sieve.cc)
target_link_libraries(PrimeSieve gtest_main)
gtest_discover_tests(PrimeSieve)
