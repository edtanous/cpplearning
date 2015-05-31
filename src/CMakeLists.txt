# Build the main executable. 
add_executable(${PROJECT_NAME} ${MAIN_SOURCE} ${PROJECT_SOURCES})


# Set the directory for "make install" to place the binary file.
install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_SOURCE_DIR}/bin)

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})

