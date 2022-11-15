
set(bindir_17 "${CMAKE_CURRENT_BINARY_DIR}/test/try_compile")
set(saved_output_17 "${bindir_17}/output.txt")
set(srcfile_17 "${CMAKE_CURRENT_LIST_DIR}/cxx_17.cpp")
try_compile(
    CXX_17_FINE
    "${bindir_17}"
    "${srcfile_17}"
    OUTPUT_VARIABLE output
)
if(NOT CXX_17_FINE)
  file(WRITE "${saved_output_17}" "${output}")
  message(
      FATAL_ERROR
      "Can't compile test file:\n"
      " ${srcfile_17}\n"
      "Error log:\n"
      " ${saved_output_17}\n"
      "Please check that your compiler supports C++17 features and C++17 standard enabled."
  )
endif()