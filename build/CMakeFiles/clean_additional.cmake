# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "CMakeFiles\\QtWidgets_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QtWidgets_autogen.dir\\ParseCache.txt"
  "QtWidgets_autogen"
  )
endif()
