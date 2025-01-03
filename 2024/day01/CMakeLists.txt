add_executable(day01 main.cpp)

file(COPY ${CMAKE_SOURCE_DIR}/2024/day01/day01-input.txt DESTINATION ${CMAKE_BINARY_DIR}/2024/day01/)
file(COPY ${CMAKE_SOURCE_DIR}/2024/day01/day01-default-input.txt DESTINATION ${CMAKE_BINARY_DIR}/2024/day01/)


target_link_options(day01 PRIVATE -stdlib=libstdc++)  # For Clang
