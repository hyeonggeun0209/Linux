add_library(util STATIC
    util.cpp
)

install(TARGETS util
ARCHIVE DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../lib
)