/*
 * KSGenPositionSpaceBuilder.cxx
 *
 *  Created on: 01.07.2014
 *      Author: oertlin
 */

#include "KSGenPositionSpaceRandomBuilder.h"

using namespace Kassiopeia;
using namespace std;

namespace katrin
{
template<> KSGenPositionSpaceRandomBuilder::~KComplexElement() = default;

STATICINT sKSGenPositionSpaceRandomStructure = KSGenPositionSpaceRandomBuilder::Attribute<std::string>("name") +
                                               KSGenPositionSpaceRandomBuilder::Attribute<std::string>("spaces");

STATICINT sKSGenPositionSpaceRandom =
    KSRootBuilder::ComplexElement<KSGenPositionSpaceRandom>("ksgen_position_space_random");

}  // namespace katrin
