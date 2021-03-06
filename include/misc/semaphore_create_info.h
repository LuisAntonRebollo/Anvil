//
// Copyright (c) 2018 Advanced Micro Devices, Inc. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
#ifndef MISC_SEMAPHORE_CREATE_INFO_H
#define MISC_SEMAPHORE_CREATE_INFO_H

#include "misc/types.h"

namespace Anvil
{
    class SemaphoreCreateInfo
    {
    public:
        /* Public functions */

        /* TODO.
         *
         * NOTE: Unless specified later with a corresponding set_..() invocation, the following parameters are assumed by default:
         *
         * - Exportable external semaphore handle type: none
         * - MT safety:                                 MT_SAFETY_INHERIT_FROM_PARENT_DEVICE
         */
        static Anvil::SemaphoreCreateInfoUniquePtr create(const Anvil::BaseDevice* in_device_ptr);

        const Anvil::BaseDevice* get_device() const
        {
            return m_device_ptr;
        }

        const Anvil::ExternalSemaphoreHandleTypeBits& get_exportable_external_semaphore_handle_types() const
        {
            return m_exportable_external_semaphore_handle_types;
        }

        const MTSafety& get_mt_safety() const
        {
            return m_mt_safety;
        }

        void set_device(const Anvil::BaseDevice* in_device_ptr)
        {
            m_device_ptr = in_device_ptr;
        }

        /* TODO
         *
         * Requires VK_KHR_external_semaphore.
         */
        void set_exportable_external_semaphore_handle_types(const Anvil::ExternalFenceHandleTypeBits& in_external_handle_types)
        {
            m_exportable_external_semaphore_handle_types = in_external_handle_types;
        }

        void set_mt_safety(const MTSafety& in_mt_safety)
        {
            m_mt_safety = in_mt_safety;
        }

    private:
        /* Private functions */
        SemaphoreCreateInfo(const Anvil::BaseDevice* in_device_ptr,
                            MTSafety                 in_mt_safety);

        /* Private variables */
        const Anvil::BaseDevice*               m_device_ptr;
        Anvil::ExternalSemaphoreHandleTypeBits m_exportable_external_semaphore_handle_types;
        Anvil::MTSafety                        m_mt_safety;

        ANVIL_DISABLE_ASSIGNMENT_OPERATOR(SemaphoreCreateInfo);
        ANVIL_DISABLE_COPY_CONSTRUCTOR(SemaphoreCreateInfo);
    };

}; /* namespace Anvil */

#endif /* MISC_SEMAPHORE_CREATE_INFO_H */