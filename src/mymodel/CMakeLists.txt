#include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )

list( APPEND mymodel_src_files
  Traits.h
  
  # # Covariance
  # Covariance/Covariance.h
  # Covariance/Covariance.cc

  # # Fields
  # Fields/Fields.h
  # Fields/Fields.cc
  
  # Geometry  
  Geometry/Geometry.h  
  Geometry/Geometry.cc
  Geometry/GeometryFortran.h
  Geometry/Geometry.interface.F90
  Geometry/Geometry.F90

  # # GeometryIterator
  # GeometryIterator/GeometryIterator.h
  # GeometryIterator/GeometryIterator.cc

  # # GetValuesTraj
  # GetValuesTraj/GetValuesTraj.h
  # GetValuesTraj/GetValuesTraj.cc
  
  # # Increment
  # Increment/Increment.h
  # Increment/Increment.cc

  # # Model
  # Model/Model.h
  # Model/Model.cc

  # # ModelAux
  # ModelAux/ModelAuxControl.h
  # ModelAux/ModelAuxControl.cc
  # ModelAux/ModelAuxIncrement.h
  # ModelAux/ModelAuxIncrement.cc
  # ModelAux/ModelAuxCovariance.h
  # ModelAux/ModelAuxCovariance.cc
  
  # # State
  # State/State.h
  # State/State.cc
  )


ecbuild_add_library( TARGET   mymodel
                     SOURCES  ${mymodel_src_files}
                     LIBS     ${NETCDF_LIBRARIES}
                              eckit eckit_mpi fckit oops ioda ufo
                     INSTALL_HEADERS LISTED
                     LINKER_LANGUAGE ${MYMODEL_LINKER_LANGUAGE}
                    )