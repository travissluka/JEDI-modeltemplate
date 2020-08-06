/*
 * (C) Copyright 2019-2020 UCAR
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 */

#ifndef MYMODEL_MODELAUX_MODELAUXCOVARIANCE_H_
#define MYMODEL_MODELAUX_MODELAUXCOVARIANCE_H_

#include <ostream>
#include <string>

#include "eckit/config/LocalConfiguration.h"

#include "oops/util/ObjectCounter.h"
#include "oops/util/Printable.h"

// forward declarations
namespace mymodel {
  class Geometry;
  class ModelAuxControl;
  class ModelAuxIncrement;
}

// -----------------------------------------------------------------------------

namespace mymodel {

class ModelAuxCovariance : public util::Printable,
                           private util::ObjectCounter<ModelAuxCovariance> {
 public:
  static const std::string classname() {return "mymodel::ModelBiasCovariance";}

  // Constructor, destructor
  ModelAuxCovariance(const eckit::Configuration &, const Geometry &);
  ~ModelAuxCovariance();

  // math operators
  void inverseMultiply(const ModelAuxIncrement &, ModelAuxIncrement &) const;
  void linearize(const ModelAuxControl &, const Geometry &);
  void multiply(const ModelAuxIncrement &, ModelAuxIncrement &);
  void randomize(ModelAuxIncrement &) const;

  // accessors
  const eckit::Configuration & config() const {return conf_;}

 private:
  void print(std::ostream & os) const;

  const eckit::LocalConfiguration conf_;
};

// -----------------------------------------------------------------------------

}  // namespace mymodel

#endif  // MYMODEL_MODELAUX_MODELAUXCOVARIANCE_H_

