cmake_minimum_required(VERSION 3.13...3.22 FATAL_ERROR)

set(
    CMAKE_TOOLCHAIN_FILE
    "${CMAKE_CURRENT_LIST_DIR}/cmake/cxx_standart_17.cmake"
    CACHE
    FILEPATH
    "Default toolchain"
)

project(loglady VERSION 1.0.0 LANGUAGES CXX)

#-----------------------------------------------------------------#
# OS dependecies                                                  #
#-----------------------------------------------------------------#

if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

if(LINUX)
    message(STATUS "Linux OS build")
    # if required in the future
    # set(ADITIONAL_LIBRARIES "")

elseif(WIN32 OR MSVC OR MSYS OR MINGW)
    message(STATUS "Windows OS build")
    # if required in the future
    # set(ADITIONAL_LIBRARIES "")

elseif(APPLE)
    message(STATUS "Mac OS build")
    # if required in the future
    # set(ADITIONAL_LIBRARIES "")

else()
    message(STATUS "OS not supported")
endif()

#-----------------------------------------------------------------#
# Libraries                                                       #
#-----------------------------------------------------------------#

set(LOCAL_INCLUDE_DIRS
    "${CMAKE_SOURCE_DIR}/src"
    "${CMAKE_SOURCE_DIR}/src/config"
    "${CMAKE_SOURCE_DIR}/src/formatter"
    )

include_directories(${LOCAL_INCLUDE_DIRS})

IF (${CMAKE_CXX_STANDARD} MATCHES "11")
    include("${CMAKE_CURRENT_LIST_DIR}/test/try_compile/cxx_11.cmake")
elseif (${CMAKE_CXX_STANDARD} MATCHES "14")
    include("${CMAKE_CURRENT_LIST_DIR}/test/try_compile/cxx_14.cmake")
elseif (${CMAKE_CXX_STANDARD} MATCHES "17")
    include("${CMAKE_CURRENT_LIST_DIR}/test/try_compile/cxx_17.cmake")
else()
    message(SEND_ERROR "Please check that your compiler supports at least C++11 features and C++11 standard enabled.")
endif()

add_compile_definitions(CXX_VERSION=${CMAKE_CXX_STANDARD})

#-----------------------------------------------------------------#
# Source files                                                    #
#-----------------------------------------------------------------#

set(SOURCE_FILES
    "${CMAKE_SOURCE_DIR}/src/logger.cpp"
    "${CMAKE_SOURCE_DIR}/src/formatter/formatter.cpp"
    "${CMAKE_SOURCE_DIR}/src/formatter/formatter_wrapper.cpp"
    "${CMAKE_SOURCE_DIR}/src/formatter/datetime_wrapper.cpp"
    "${CMAKE_SOURCE_DIR}/src/formatter/level_wrapper.cpp"
    "${CMAKE_SOURCE_DIR}/src/formatter/config_formatter.cpp"
    )

add_executable(loglady ${SOURCE_FILES})

target_include_directories(loglady PRIVATE ${LOCAL_INCLUDE_DIRS})