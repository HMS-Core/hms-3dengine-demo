/*

 * Copyright (c) Huawei Technologies Co., Ltd. 2022. All rights reserved.

 * Description: The initialization system component code for the project.

 * Author: LiaoHaoMing l00609790

 * Create: 2022-08-12

 */

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

#include "BallgameSystemComponent.h"

namespace Ballgame
{
    void BallgameSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<BallgameSystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<BallgameSystemComponent>("Ballgame", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void BallgameSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("BallgameService"));
    }

    void BallgameSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("BallgameService"));
    }

    void BallgameSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void BallgameSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }
    
    BallgameSystemComponent::BallgameSystemComponent()
    {
        if (BallgameInterface::Get() == nullptr)
        {
            BallgameInterface::Register(this);
        }
    }

    BallgameSystemComponent::~BallgameSystemComponent()
    {
        if (BallgameInterface::Get() == this)
        {
            BallgameInterface::Unregister(this);
        }
    }

    void BallgameSystemComponent::Init()
    {
    }

    void BallgameSystemComponent::Activate()
    {
        BallgameRequestBus::Handler::BusConnect();
    }

    void BallgameSystemComponent::Deactivate()
    {
        BallgameRequestBus::Handler::BusDisconnect();
    }
}
