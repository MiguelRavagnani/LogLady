
set(bindir_14 "${CMAKE_CURRENT_BINARY_DIR}/test/try_compile")
set(saved_output_14 "${bindir_14}/output.txt")
set(srcfile_14 "${CMAKE_CURRENT_LIST_DIR}/cxx_14.cpp")
try_compile(
    CXX_14_FINE
    "${bindir_14}"
    "${srcfile_14}"
    OUTPUT_VARIABLE output
)
if(NOT CXX_14_FINE)
  file(WRITE "${saved_output_14}" "${output}")
  message(
      FATAL_ERROR
      "Can't compile test file:\n"
      " ${srcfile_14}\n"
      "Error log:\n"
      " ${saved_output_14}\n"
      "Please check that your compiler supports C++14 features and C++14 standard enabled."
  )
endif()