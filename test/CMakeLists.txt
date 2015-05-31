# The test suite name is the project name with _test appended to it.
set(TEST_NAME ${PROJECT_NAME}_test)

# Append the project sources to the list of test sources, appending the
# "../src" relative path for each.
foreach(source ${PROJECT_SOURCES})
    list(APPEND TEST_SOURCES ../src/${source})
endforeach(source)

# Build the test executable.
add_executable(${TEST_NAME} ${TEST_SOURCES})

# gtest was not found with a find_package command and must be linked to
# explicitly.
target_link_libraries(${TEST_NAME} gtest_main)

add_custom_target(runtest
		COMMAND ${TEST_NAME}
		WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
		COMMENT "Running tests.")



