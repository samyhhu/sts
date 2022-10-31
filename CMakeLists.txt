cmake_minimum_required(VERSION 3.14)

# for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_FRAMEWORK_PATH ${CMAKE_SOURCE_DIR}/conan)

include(cmake/prelude.cmake)

project(
    sts
    VERSION 0.1.0
    DESCRIPTION "S' Trading System"
    HOMEPAGE_URL "N/A"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(
    sts_lib OBJECT
    source/lib.cpp
)

target_include_directories(
    sts_lib ${warning_guard}
    PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source>"
)

target_compile_features(sts_lib PUBLIC cxx_std_20)

find_package(fmt REQUIRED)
find_package(spdlog REQUIRED)
target_link_libraries(sts_lib PRIVATE fmt::fmt)

# ---- Declare executable ----

add_executable(sts_exe source/main.cpp)
add_executable(sts::exe ALIAS sts_exe)

set_target_properties(
    sts_exe PROPERTIES
    OUTPUT_NAME sts
    EXPORT_NAME exe
)

target_compile_features(sts_exe PRIVATE cxx_std_20)

target_link_libraries(sts_exe PRIVATE sts_lib spdlog::spdlog)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT sts_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of sts"
  )
endif()

include(cmake/dev-mode.cmake)
