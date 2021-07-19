cmake_minimum_required(VERSION 3.13)
project(NVMR-JSON VERSION 1.0.0)

include(GNUInstallDirs)
find_package(Qt5 COMPONENTS Core REQUIRED)

set( headers
    videosendermessage.h
    videosenderconfiguration.h
    videosettings.h
    networksettings.h
    streaminformation.h
)

set( sources
    videosendermessage.cpp
    videosenderconfiguration.cpp
    videosettings.cpp
    networksettings.cpp
    streaminformation.cpp
)

add_library( nvmr-json SHARED ${headers} ${sources} )
target_link_libraries( nvmr-json Qt5::Core )
set_target_properties( nvmr-json PROPERTIES 
    SOVERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    VERSION ${PROJECT_VERSION}
)

if( UNIX )
    #
    # pkg-config information
    #
    SET(PKG_CONFIG_LIBDIR
        "\${prefix}/lib"
    )
    SET(PKG_CONFIG_INCLUDEDIR
        "\${prefix}/include/nvmr-json"
    )
    SET(PKG_CONFIG_LIBS
        "-lnvmr-json"
    )
    SET(PKG_CONFIG_CFLAGS
        "-I\${includedir}"
    )

    CONFIGURE_FILE(
        "${CMAKE_CURRENT_SOURCE_DIR}/nvmr-json.pc.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/nvmr-json.pc"
    )
    install( FILES "${CMAKE_BINARY_DIR}/nvmr-json.pc"
             DESTINATION "${CMAKE_INSTALL_LIBDIR}/pkgconfig" )
endif( UNIX )

#
# Installation information for the library
#
install( TARGETS nvmr-json
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
)
install( FILES ${headers}
    DESTINATION include/nvmr-json
)
