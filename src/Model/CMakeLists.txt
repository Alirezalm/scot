cmake_minimum_required(VERSION 3.22)

file(GLOB SCOT_MODEL "*.cpp")

add_library(model STATIC ${SCOT_MODEL})

target_include_directories(model PRIVATE
        "${CMAKE_SOURCE_DIR}/DOSE"
        "$ENV{GUROBI_HOME}/include"
        "${CMAKE_SOURCE_DIR}/ExternLibs/spdlog"
)

set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

file(GLOB INC "*.h")

install(TARGETS model DESTINATION lib )

#install(FILES ${INC} DESTINATION Model )