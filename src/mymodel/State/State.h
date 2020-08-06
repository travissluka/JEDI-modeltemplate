/*
 * (C) Copyright 2019-2020 UCAR
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 */

#ifndef MYMODEL_STATE_STATE_H_
#define MYMODEL_STATE_STATE_H_

#include <memory>
#include <ostream>
#include <string>

#include <boost/shared_ptr.hpp>

#include "eckit/mpi/Comm.h"

#include "oops/base/Variables.h"
#include "oops/util/DateTime.h"
#include "oops/util/ObjectCounter.h"
#include "oops/util/Printable.h"

// forward declarations
namespace eckit {
  class Configuration;
}
namespace ufo {
  class GeoVaLs;
  class Locations;
}
namespace mymodel {
  class Geometry;
  class Increment;
}

// ----------------------------------------------------------------------------

namespace mymodel {

  // State class
  class State : public util::Printable,
                private util::ObjectCounter<State> {
   public:
    static const std::string classname() {return "mymodel::State";}

    // constructors, destructors
    State(const Geometry &, const eckit::Configuration &);
    State(const Geometry &, const oops::Variables &,
          const util::DateTime &);
    State(const Geometry &, const State &);
    State(const State &);
    ~State();

    // math operators
    State & operator+=(const Increment &);
    void accumul(const double &, const State &);
    double norm() const;
    void zero();

    // I/O
    void read(const eckit::Configuration &);
    void write(const eckit::Configuration &) const;

    // time manipulation
    void updateTime(const util::Duration & dt) { time_ += dt; }
    const util::DateTime & validTime() const { return time_; }
    util::DateTime & validTime() { return time_; }

    // other accessors
    boost::shared_ptr<const Geometry> geometry() const;
    const oops::Variables & variables() const { return vars_; }

   private:
    void print(std::ostream &) const;

    boost::shared_ptr<const Geometry> geom_;
    oops::Variables vars_;
    util::DateTime time_;
  };
}  // namespace mymodel

#endif  // MYMODEL_STATE_STATE_H_
