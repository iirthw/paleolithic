# Download GoogleTest as an external project
include(${PROJECT_SOURCE_DIR}/cmake/download_gtest.cmake)

project(RunUnitTests)
set(SOURCE_FILES test_dyn_prog.cc)
add_executable(${PROJECT_NAME} main.cc ${SOURCE_FILES})
# set VS startup project
set_property(
    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME}
    )

get_target_property(MAIN_LIBRARY_INCLUDES ${CMAKE_PROJECT_NAME} INCLUDE_DIRECTORIES)
target_include_directories(${PROJECT_NAME} PUBLIC ${MAIN_LIBRARY_INCLUDES})
target_link_libraries(${PROJECT_NAME} ${CMAKE_PROJECT_NAME} gtest)

# Uncomment the following, if test resources are needed
# configure_file(
#    ${CMAKE_CURRENT_SOURCE_DIR}/resources/simple.json 
#    ${CMAKE_CURRENT_BINARY_DIR}/resources/simple.json COPYONLY
# )
