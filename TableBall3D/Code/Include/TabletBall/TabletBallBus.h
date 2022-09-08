
#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace TabletBall
{
    class TabletBallRequests
    {
    public:
        AZ_RTTI(TabletBallRequests, "{07ee286f-9985-4991-b2d5-951ebc8cd661}");
        virtual ~TabletBallRequests() = default;
        // Put your public methods here
    };
    
    class TabletBallBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using TabletBallRequestBus = AZ::EBus<TabletBallRequests, TabletBallBusTraits>;
    using TabletBallInterface = AZ::Interface<TabletBallRequests>;

} // namespace TabletBall
