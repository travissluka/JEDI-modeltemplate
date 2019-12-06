/*
 * (C) Copyright 2019-2019 UCAR
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 */

#include "mymodel/Fields/Fields.h"
#include "mymodel/Geometry/Geometry.h"

#include "eckit/config/Configuration.h"

#include "oops/base/Variables.h"
#include "oops/util/abor1_cpp.h"

namespace mymodel {

// ----------------------------------------------------------------------------

  Fields::Fields(const Geometry & geom, const oops::Variables & vars,
               const eckit::Configuration & conf)
    : geom_(new Geometry(geom)) {
    util::abor1_cpp("Fields::Fields() needs to be implemented.",
                    __FILE__, __LINE__);
    // time_ = util::DateTime("2018-04-15T00:00:00Z");
  }

// ----------------------------------------------------------------------------

  Fields::~Fields() {
    util::abor1_cpp("Fields::~Fields() needs to be implemented.",
                    __FILE__, __LINE__);
  }

// ----------------------------------------------------------------------------

  void Fields::print(std::ostream & os) const {
    util::abor1_cpp("Fields::print() needs to be implemented.",
                    __FILE__, __LINE__);
    os << "(TODO, print diagnostic info about the fields here)"
       << std::endl;
  }

// ----------------------------------------------------------------------------

  double Fields::norm() const {
    util::abor1_cpp("Fields::norm() needs to be implemented.",
                    __FILE__, __LINE__);
    return 0.0;
  }

// ----------------------------------------------------------------------------

  boost::shared_ptr<const Geometry> Fields::geometry() const {
    return geom_;
  }

// ----------------------------------------------------------------------------

}  // namespace mymodel