add_executable(my_prog main.cpp)

target_link_libraries(my_prog util)

install(TARGETS my_prog
RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../bin
)