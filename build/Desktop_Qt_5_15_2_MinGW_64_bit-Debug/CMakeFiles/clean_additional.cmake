# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\hw-003_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\hw-003_autogen.dir\\ParseCache.txt"
  "hw-003_autogen"
  )
endif()
