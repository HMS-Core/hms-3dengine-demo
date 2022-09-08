/*

 * Copyright (c) Huawei Technologies Co., Ltd. 2022. All rights reserved.

 * Description: The initialization system component code for the project.

 * Author: LiaoHaoMing l00609790

 * Create: 2022-08-12

 */

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

#include "TabletBallSystemComponent.h"

namespace TabletBall
{
    void TabletBallSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<TabletBallSystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<TabletBallSystemComponent>("TabletBall", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void TabletBallSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("TabletBallService"));
    }

    void TabletBallSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("TabletBallService"));
    }

    void TabletBallSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void TabletBallSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }
    
    TabletBallSystemComponent::TabletBallSystemComponent()
    {
        if (TabletBallInterface::Get() == nullptr)
        {
            TabletBallInterface::Register(this);
        }
    }

    TabletBallSystemComponent::~TabletBallSystemComponent()
    {
        if (TabletBallInterface::Get() == this)
        {
            TabletBallInterface::Unregister(this);
        }
    }

    void TabletBallSystemComponent::Init()
    {
    }

    void TabletBallSystemComponent::Activate()
    {
        TabletBallRequestBus::Handler::BusConnect();
    }

    void TabletBallSystemComponent::Deactivate()
    {
        TabletBallRequestBus::Handler::BusDisconnect();
    }
}
