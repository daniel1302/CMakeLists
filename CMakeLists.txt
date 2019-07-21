cmake_minimum_required(VERSION 2.8.12)
project(cmake_skeleton)

option(WITH_GTEST "Enable test" OFF)


# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# set(CMAKE_CURRENT_BINARY_DIR  ${CMAKE_BINARY_DIR}/bin)
add_definitions("-std=c++17")

include_directories(src)
add_executable(${PROJECT_NAME} src/squareRoot.cpp)
target_sources(${PROJECT_NAME} PUBLIC main.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

message("WITH_GTEST ${WITH_GTEST}")
if ( WITH_GTEST STREQUAL "ON" )
    message("Google Tests are enabled ${GTEST_ENABLE}")
    enable_testing()

    set(BENCHMARK_ENABLE_TESTING 0)
    add_subdirectory(vendor/google/googletest)
    add_subdirectory(vendor/google/benchmark)

    file(GLOB_RECURSE ALL_TESTS_CPP tests/*.t.cpp)
    foreach(ONE_TEST_CPP ${ALL_TESTS_CPP})
        get_filename_component(ONE_TEST_EXEC ${ONE_TEST_CPP} NAME_WE)


        set(TARGET_NAME ${ONE_TEST_EXEC}Test)
        add_executable(${TARGET_NAME} ${ONE_TEST_CPP})
        # set_target_properties(${TARGET_NAME} PROPERTIES OUTPUT_NAME bin/$${ONE_TEST_EXEC})
        target_link_libraries(${TARGET_NAME}
            benchmark
            gtest
            ${CMAKE_THREAD_LIBS_INIT}
        )

        add_test(NAME ${TARGET_NAME} COMMAND ${TARGET_NAME})
    endforeach()



    file(GLOB_RECURSE ALL_BENCH_CPP benchmarks/*.bench.cpp)
    foreach(ONE_BENCH_CPP ${ALL_BENCH_CPP})
        get_filename_component(ONE_BENCH_EXEC ${ONE_BENCH_CPP} NAME_WE)


        set(TARGET_NAME ${ONE_BENCH_EXEC}Benchmark)
        add_executable(${TARGET_NAME} ${ONE_BENCH_CPP})
        # set_target_properties(${TARGET_NAME} PROPERTIES OUTPUT_NAME bin/$${ONE_BENCH_EXEC})
        target_link_libraries(${TARGET_NAME}
            benchmark
            ${CMAKE_THREAD_LIBS_INIT}
        )

        add_test(NAME ${TARGET_NAME} COMMAND ${TARGET_NAME})
    endforeach()
endif()