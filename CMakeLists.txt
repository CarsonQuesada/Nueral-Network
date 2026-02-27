cmake_minimum_required(VERSION 3.10)
project(NeuralNetwork LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(neural_network src/Main.cpp)
set_target_properties(neural_network PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/out/bin"
)
set_target_properties(neural_network PROPERTIES
  PDB_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/out/symbols"
)

target_sources(neural_network
    PRIVATE
        src/NeuralNetwork.cpp
        src/DataSet.cpp
        src/Math/Math.cpp
        src/Math/Matrix.cpp

    PUBLIC
        FILE_SET HEADERS
        FILES
            include/NeuralNetwork/NeuralNetwork.h
            include/NeuralNetwork/DataSet.h
            include/NeuralNetwork/Math/Math.h
            include/NeuralNetwork/Math/Matrix.h
)

target_include_directories(neural_network PRIVATE ${PROJECT_SOURCE_DIR}/include)

add_custom_command(TARGET neural_network POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${PROJECT_SOURCE_DIR}/DataSets
            $<TARGET_FILE_DIR:neural_network>/DataSets
)
