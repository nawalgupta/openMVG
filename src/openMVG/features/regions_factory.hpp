
// Copyright (c) 2015 Pierre MOULON.

// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef OPENMVG_FEATURES_REGIONS_FACTORY_HPP
#define OPENMVG_FEATURES_REGIONS_FACTORY_HPP

#include "openMVG/features/regions.hpp"

namespace openMVG {
namespace features {

/// Define the classic SIFT Keypoint
using SIFT_Regions = Scalar_Regions<SIOPointFeature,unsigned char,128>;

/// Define the AKAZE Keypoint (with a float descriptor)
using AKAZE_Float_Regions = Scalar_Regions<SIOPointFeature,float,64>;
/// Define the AKAZE Keypoint (with a LIOP descriptor)
using AKAZE_Liop_Regions = Scalar_Regions<SIOPointFeature,unsigned char,144>;
/// Define the AKAZE Keypoint (with a binary descriptor saved in an uchar array)
using AKAZE_Binary_Regions = Binary_Regions<SIOPointFeature,64>;

} // namespace features
} // namespace openMVG

//--
// Register region type for serialization
//--
#include <cereal/cereal.hpp>
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/json.hpp>
CEREAL_REGISTER_TYPE_WITH_NAME(openMVG::features::SIFT_Regions, "SIFT_Regions");
CEREAL_REGISTER_POLYMORPHIC_RELATION(openMVG::features::Regions, openMVG::features::SIFT_Regions)
CEREAL_REGISTER_TYPE_WITH_NAME(openMVG::features::AKAZE_Float_Regions, "AKAZE_Float_Regions");
CEREAL_REGISTER_POLYMORPHIC_RELATION(openMVG::features::Regions, openMVG::features::AKAZE_Float_Regions)
CEREAL_REGISTER_TYPE_WITH_NAME(openMVG::features::AKAZE_Liop_Regions, "AKAZE_Liop_Regions");
CEREAL_REGISTER_POLYMORPHIC_RELATION(openMVG::features::Regions, openMVG::features::AKAZE_Liop_Regions)
CEREAL_REGISTER_TYPE_WITH_NAME(openMVG::features::AKAZE_Binary_Regions, "AKAZE_Binary_Regions");
CEREAL_REGISTER_POLYMORPHIC_RELATION(openMVG::features::Regions, openMVG::features::AKAZE_Binary_Regions)

#endif // OPENMVG_FEATURES_REGIONS_FACTORY_HPP
