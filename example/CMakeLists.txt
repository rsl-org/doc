project(rsl C CXX)

function(DEFINE_EXAMPLE TARGET)
  add_executable(rsldoc_${TARGET} "${TARGET}.cpp")
  target_link_libraries(rsldoc_${TARGET} PRIVATE rsldoc)
  # target_link_libraries(rsldoc_${TARGET} PRIVATE rsldoc_main)
endfunction()

define_example(test)