# Parent project does not export its library target, so this CML implicitly
# depends on being added from it, i.e. the testing is done only from the build
# tree and is not feasible from an install location

project(stsTests LANGUAGES CXX)

# ---- Dependencies ----

find_package(GTest REQUIRED)

include(GoogleTest)
include_directories(${CMAKE_INCLUDE_PATH})
# ---- Tests ----

add_executable(sts_test source/sts_test.cpp)
target_link_libraries(
    sts_test PUBLIC
    sts_lib
    GTest::gtest
    GTest::gtest_main
)
target_compile_features(sts_test PRIVATE cxx_std_20)
gtest_discover_tests(sts_test)

# ---- End-of-file commands ----

add_folders(Test)
