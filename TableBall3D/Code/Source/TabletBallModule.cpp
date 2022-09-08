/*

 * Copyright (c) Huawei Technologies Co., Ltd. 2022. All rights reserved.

 * Description: Project initialization module code.

 * Author: LiaoHaoMing l00609790

 * Create: 2022-08-12

 */

#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "TabletBallSystemComponent.h"

namespace TabletBall
{
    class TabletBallModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(TabletBallModule, "{d5a5623b-8664-40ff-8921-167b0a2289e2}", AZ::Module);
        AZ_CLASS_ALLOCATOR(TabletBallModule, AZ::SystemAllocator, 0);

        TabletBallModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                TabletBallSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<TabletBallSystemComponent>(),
            };
        }
    };
} // namespace TabletBall

AZ_DECLARE_MODULE_CLASS(Gem_TabletBall, TabletBall::TabletBallModule)
