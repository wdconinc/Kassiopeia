#include "KSRootTerminatorBuilder.h"

#include "KSRootBuilder.h"

using namespace Kassiopeia;
using namespace std;

namespace katrin
{

template<> KSRootTerminatorBuilder::~KComplexElement() = default;

STATICINT sKSRootTerminator = KSRootBuilder::ComplexElement<KSRootTerminator>("ks_root_terminator");

STATICINT sKSRootTerminatorStructure = KSRootTerminatorBuilder::Attribute<std::string>("name") +
                                       KSRootTerminatorBuilder::Attribute<std::string>("add_terminator");

}  // namespace katrin
