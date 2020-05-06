#ifndef KSURFACETYPES_DEF
#define KSURFACETYPES_DEF

#include "KTypelist.hh"

#include <complex>

namespace KEMField
{
class KElectrostaticBasis;
class KMagnetostaticBasis;
class KElectromagneticBasis;

// A list of all of the basis types
typedef KTYPELIST_3(KElectrostaticBasis, KMagnetostaticBasis, KElectromagneticBasis) KBasisTypes_;
}  // namespace KEMField

namespace KEMField
{
struct KDirichletBoundary;
struct KNeumannBoundary;
struct KCauchyBoundary;
struct KRobinBoundary;
struct KIsolatedBoundary;

// A list of all of the boundary types
typedef KTYPELIST_5(KDirichletBoundary, KNeumannBoundary, KCauchyBoundary, KRobinBoundary,
                    KIsolatedBoundary) KBoundaryTypes_;
}  // namespace KEMField

namespace KEMField
{
class KTriangle;
class KRectangle;
class KLineSegment;
class KConicSection;
class KRing;
template<class ShapePolicy> class KSymmetryGroup;

typedef KSymmetryGroup<KTriangle> KTriangleGroup;
typedef KSymmetryGroup<KRectangle> KRectangleGroup;
typedef KSymmetryGroup<KLineSegment> KLineSegmentGroup;
typedef KSymmetryGroup<KConicSection> KConicSectionGroup;
typedef KSymmetryGroup<KRing> KRingGroup;

// A list of all of the shape types
typedef KTYPELIST_10(KTriangle, KRectangle, KLineSegment, KConicSection, KRing, KRectangleGroup, KLineSegmentGroup,
                     KTriangleGroup, KConicSectionGroup, KRingGroup) KShapeTypes_;
}  // namespace KEMField

namespace KEMField
{
/**
* KBasisTypes is a typelist of all available basis types.
*/
typedef NoDuplicates<KBasisTypes_>::Result KBasisTypes;
/**
* KBoundaryTypes is a typelist of all available boundary types.
*/
typedef NoDuplicates<KBoundaryTypes_>::Result KBoundaryTypes;
/**
* KShapeTypes is a typelist of all available shape types.
*/
typedef NoDuplicates<KShapeTypes_>::Result KShapeTypes;
}  // namespace KEMField

#include "../../../Surfaces/include/KBoundary.hh"
#include "../../../Surfaces/include/KConicSection.hh"
#include "../../../Surfaces/include/KElectromagneticBasis.hh"
#include "../../../Surfaces/include/KElectrostaticBasis.hh"
#include "../../../Surfaces/include/KLineSegment.hh"
#include "../../../Surfaces/include/KMagnetostaticBasis.hh"
#include "../../../Surfaces/include/KRectangle.hh"
#include "../../../Surfaces/include/KRing.hh"
#include "../../../Surfaces/include/KSurfaceVisitors.hh"
#include "../../../Surfaces/include/KSymmetryGroup.hh"
#include "../../../Surfaces/include/KTriangle.hh"

#endif /* KSURFACETYPES_DEF */
