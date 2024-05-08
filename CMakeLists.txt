cmake_minimum_required(VERSION 3.16)

project(link_my_library)

# Locate Open3D Library dependency
find_package(Open3D REQUIRED HINTS ${PROJECT_SOURCE_DIR}/open3d/lib/cmake)


# Your Build System Code starts here
add_library (my_viewer SHARED ${CMAKE_CURRENT_SOURCE_DIR}/my_viewer/my_viewer.cpp)


# add executable main
target_link_libraries (my_viewer PUBLIC Open3D::Open3D)
add_executable (main ${CMAKE_CURRENT_SOURCE_DIR}/app/main.cpp)

target_link_libraries(main PRIVATE my_viewer)

# tell cmake where to look for *.hpp , *.h files
target_include_directories (main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})



# Define library C++ standard
# target_compile_features (my_viewer PRIVATE cxx_std_17)


# tell cmake where to look for *.hpp , *.h files
# target_include_directories (my_viewer PUBLIC ${PROJECT_SOURCE_DIR}/my_viewer/my_viewer.hpp)


# Define compiler options , target based
# target_compile_options (my_viewer PRIVATE -Wall -Werror )


# add executable main
# add_executable (main src/main.cpp)
