cmake_minimum_required(VERSION 3.15)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 26)


project(rsl CXX)

add_library(rsldoc)
target_compile_options(rsldoc PUBLIC 
  "-stdlib=libc++"
  "-freflection"
  "-fannotation-attributes"
  "-fparameter-reflection"
  "-fexpansion-statements"
  # "-Wno-c++26-extensions"
  # "-ftime-trace"
  # "-fconstexpr-steps=10000000" # required to scan the global namespace
)
target_include_directories(rsldoc PUBLIC include)

# add_library(rsldoc_main)
# target_link_libraries(rsldoc_main PUBLIC rsldoc)

add_subdirectory(src)
add_subdirectory(example)

set_target_properties(rsldoc PROPERTIES PUBLIC_HEADER "include/rsl/doc")
install(TARGETS rsldoc)
