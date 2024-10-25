project(file2array_test)

include_directories(${PROJECT_SOURCE_DIR}/../../src)

set(GTEST_LIBRARIES gtest gtest_main)

set(FILE2ARRAY_TEST_SOURCE_FILES
        program_test.cpp
)

add_executable(file2array_test
        main.cpp
        ${FILE2ARRAY_TEST_SOURCE_FILES}
)

target_link_libraries(file2array_test file2array ${GTEST_LIBRARIES})
