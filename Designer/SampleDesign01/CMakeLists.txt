cmake_minimum_required (VERSION 3.21.1)

project(SampleDesign01 VERSION 0.0.1 LANGUAGES C CXX ASM)

if (NOT TARGET Qul::Core)
    find_package(Qul)
endif()

if (Qul_VERSION LESS "2.4")
    message(WARNING "The current Qt for MCUs version is '${Qul_VERSION}'."
                    "This CMake project was made for Qt for MCUs 2.4 and newer, "
                    "and might not work as expected.")
endif()

qul_add_target(SampleDesign01 QML_PROJECT SampleDesign01.qmlproject GENERATE_ENTRYPOINT)
app_target_setup_os(SampleDesign01)
