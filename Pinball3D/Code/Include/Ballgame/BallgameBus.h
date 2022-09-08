
#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace Ballgame
{
    class BallgameRequests
    {
    public:
        AZ_RTTI(BallgameRequests, "{b8ff1771-6143-4867-843f-0838e78108c0}");
        virtual ~BallgameRequests() = default;
        // Put your public methods here
    };
    
    class BallgameBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using BallgameRequestBus = AZ::EBus<BallgameRequests, BallgameBusTraits>;
    using BallgameInterface = AZ::Interface<BallgameRequests>;

} // namespace Ballgame
