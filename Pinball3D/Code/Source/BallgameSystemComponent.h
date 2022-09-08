
#pragma once

#include <AzCore/Component/Component.h>

#include <Ballgame/BallgameBus.h>

namespace Ballgame
{
    class BallgameSystemComponent
        : public AZ::Component
        , protected BallgameRequestBus::Handler
    {
    public:
        AZ_COMPONENT(BallgameSystemComponent, "{bdaa9ddc-8a8c-4885-9206-e8dbdb411cfb}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        BallgameSystemComponent();
        ~BallgameSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // BallgameRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
