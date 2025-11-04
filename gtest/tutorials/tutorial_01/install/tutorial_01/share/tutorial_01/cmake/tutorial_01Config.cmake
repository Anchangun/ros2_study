# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_tutorial_01_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED tutorial_01_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(tutorial_01_FOUND FALSE)
  elseif(NOT tutorial_01_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(tutorial_01_FOUND FALSE)
  endif()
  return()
endif()
set(_tutorial_01_CONFIG_INCLUDED TRUE)

# output package information
if(NOT tutorial_01_FIND_QUIETLY)
  message(STATUS "Found tutorial_01: 0.0.0 (${tutorial_01_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'tutorial_01' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${tutorial_01_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(tutorial_01_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${tutorial_01_DIR}/${_extra}")
endforeach()
