#include "KSGenEnergyLeadEventBuilder.h"

#include "KSRootBuilder.h"

using namespace Kassiopeia;
using namespace std;

namespace katrin
{

template<> KSGenEnergyLeadEventBuilder::~KComplexElement() = default;

STATICINT sKSGenEnergyLeadEventStructure = KSGenEnergyLeadEventBuilder::Attribute<std::string>("name") +
                                           KSGenEnergyLeadEventBuilder::Attribute<bool>("force_conversion") +
                                           KSGenEnergyLeadEventBuilder::Attribute<bool>("do_conversion") +
                                           KSGenEnergyLeadEventBuilder::Attribute<bool>("do_auger");

STATICINT sKSGenEnergyLeadEvent = KSRootBuilder::ComplexElement<KSGenEnergyLeadEvent>("ksgen_energy_lead_event");

}  // namespace katrin
