file(GLOB CPP_SOURCES "*.cpp")

add_executable(KIniTest ${CPP_SOURCES})
target_compile_features(KIniTest PUBLIC cxx_std_17)
set_target_properties(KIniTest PROPERTIES CXX_EXTENSIONS OFF
										  RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
target_link_libraries(KIniTest KIni -static)