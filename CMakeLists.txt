cmake_minimum_required(VERSION 3.13)
project(c-tap-test)

include(FindPkgConfig)
pkg_check_modules(CHECK REQUIRED check)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu99 -Wall -Wextra -Werror")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0 -g -DDEBUG")

enable_testing()

include_directories(${CHECK_INCLUDE_DIRS})

file(GLOB TEST_SOURCE_FILES "*.c")

foreach(CURRENT_TEST_SOURCE_FILE ${TEST_SOURCE_FILES})
  get_filename_component(CURRENT_TEST_BINARY ${CURRENT_TEST_SOURCE_FILE} NAME_WE)
  string(REPLACE "test_" "" CURRENT_TEST ${CURRENT_TEST_BINARY})

  add_executable(${CURRENT_TEST_BINARY} ${CURRENT_TEST_SOURCE_FILE})
  target_link_libraries(${CURRENT_TEST_BINARY} ${CHECK_LIBRARIES} pthread)

  add_test(${CURRENT_TEST} ${CURRENT_TEST_BINARY})
endforeach()
