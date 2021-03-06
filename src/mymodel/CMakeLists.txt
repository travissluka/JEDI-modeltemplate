#include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )

# the source code in this directory,
# all other files are handled through the subdirectory's respective CMakeLists.txt
list( APPEND mymodel_src_files
  Traits.h
)

# a convenience frunction to make adding source files from subdirectories easier
# (To keep from having to use the full path every time)
function(mymodel_target_sources)
  foreach( src IN LISTS ARGN)
    target_sources(mymodel PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/${src})
  endforeach()
endfunction()

# the main library for this interface
ecbuild_add_library( TARGET   mymodel
                     SOURCES  ${mymodel_src_files}
                     LIBS     ${NETCDF_LIBRARIES}
                              eckit eckit_mpi fckit oops ioda ufo
                     INSTALL_HEADERS LISTED
                     LINKER_LANGUAGE ${MYMODEL_LINKER_LANGUAGE}
                    )

# add source code in the subdirectories
# TODO(template_impl) add_subdirectory(Covariance)
add_subdirectory(Geometry)
# TODO(template_impl) add_subdirectory(GeometryIterator)
# TODO(template_impl) add_subdirectory(GetValues)
# TODO(template_impl) add_subdirectory(Increment)
# TODO(template_impl) add_subdirectory(Model)
# TODO(template_impl) add_subdirectory(ModelAux)
# TODO(template_impl) add_subdirectory(State)