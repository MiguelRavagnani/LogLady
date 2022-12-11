
set(bindir_11 "${CMAKE_CURRENT_BINARY_DIR}/test/try_compile")
set(saved_output_11 "${bindir_11}/output.txt")
set(srcfile_11 "${CMAKE_CURRENT_LIST_DIR}/cxx_11.cpp")
try_compile(
    CXX_11_FINE
    "${bindir_11}"
    "${srcfile_11}"
    OUTPUT_VARIABLE output
)
if(NOT CXX_11_FINE)
  file(WRITE "${saved_output_11}" "${output}")
  message(
      FATAL_ERROR
      "Can't compile test file:\n"
      " ${srcfile_11}\n"
      "Error log:\n"
      " ${saved_output_11}\n"
      "Please check that your compiler supports C++11 features and C++11 standard enabled."
  )
endif()