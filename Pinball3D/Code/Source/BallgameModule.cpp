/*

 * Copyright (c) Huawei Technologies Co., Ltd. 2022. All rights reserved.

 * Description: Project initialization module code.

 * Author: LiaoHaoMing l00609790

 * Create: 2022-08-12

 */

#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "BallgameSystemComponent.h"

namespace Ballgame
{
    class BallgameModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(BallgameModule, "{b075f673-355e-4949-9dac-b79b9c9ec608}", AZ::Module);
        AZ_CLASS_ALLOCATOR(BallgameModule, AZ::SystemAllocator, 0);

        BallgameModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                BallgameSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<BallgameSystemComponent>(),
            };
        }
    };
} // namespace Ballgame

AZ_DECLARE_MODULE_CLASS(Gem_Ballgame, Ballgame::BallgameModule)
