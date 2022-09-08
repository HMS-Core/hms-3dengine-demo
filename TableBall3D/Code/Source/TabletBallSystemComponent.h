
#pragma once

#include <AzCore/Component/Component.h>

#include <TabletBall/TabletBallBus.h>

namespace TabletBall
{
    class TabletBallSystemComponent
        : public AZ::Component
        , protected TabletBallRequestBus::Handler
    {
    public:
        AZ_COMPONENT(TabletBallSystemComponent, "{817349b0-a63c-4f26-ba36-ee006fc9215d}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        TabletBallSystemComponent();
        ~TabletBallSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // TabletBallRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
