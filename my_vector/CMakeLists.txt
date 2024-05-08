add_library(my_vector STATIC myvector.cpp)
target_include_directories(my_vector PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(my_vector PRIVATE cxx_std_17)
