cmake_minimum_required(VERSION 3.1)
project(subprojlib)

include(${CAKE_ROOT}/Cake.cmake)

option(SUBPROJLIB_WITH_ZLIB 0)

set(CMAKE_DEBUG_POSTFIX _d)

add_library(subprojlib subprojlib.c)

if(SUBPROJLIB_WITH_ZLIB)
  cake_find_package(ZLIB REQUIRED URL https://github.com/madler/zlib.git?depth=1)
  target_link_libraries(subprojlib PRIVATE ZLIB::ZLIB)
  target_compile_definitions(subprojlib PRIVATE HAVE_ZLIB)
endif()

target_include_directories(subprojlib
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

install(TARGETS subprojlib EXPORT subprojlibExport
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
)
install(EXPORT subprojlibExport DESTINATION cmake)
install(FILES include/subprojlib.h DESTINATION include)

configure_file(subprojlib-config.cmake.in hide/subprojlib-config.cmake @ONLY)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/hide/subprojlib-config.cmake DESTINATION cmake)
