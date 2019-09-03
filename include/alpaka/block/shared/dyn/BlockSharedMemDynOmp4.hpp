/* Copyright 2019 Benjamin Worpitz, René Widera
 *
 * This file is part of Alpaka.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once

#ifdef ALPAKA_ACC_CPU_BT_OMP4_ENABLED

#if _OPENMP < 201307
    #error If ALPAKA_ACC_CPU_BT_OMP4_ENABLED is set, the compiler has to support OpenMP 4.0 or higher!
#endif

#include <alpaka/block/shared/dyn/Traits.hpp>

#include <type_traits>

namespace alpaka
{
    namespace block
    {
        namespace shared
        {
            namespace dyn
            {
                //#############################################################################
                //! The GPU CUDA block shared memory allocator.
                class BlockSharedMemDynOmp4
                {
                public:
                    using BlockSharedMemDynBase = BlockSharedMemDynOmp4;

                    //-----------------------------------------------------------------------------
                    BlockSharedMemDynOmp4(size_t) {}
                    //-----------------------------------------------------------------------------
                    BlockSharedMemDynOmp4(BlockSharedMemDynOmp4 const &) = delete;
                    //-----------------------------------------------------------------------------
                    BlockSharedMemDynOmp4(BlockSharedMemDynOmp4 &&) = delete;
                    //-----------------------------------------------------------------------------
                    auto operator=(BlockSharedMemDynOmp4 const &) -> BlockSharedMemDynOmp4 & = delete;
                    //-----------------------------------------------------------------------------
                    auto operator=(BlockSharedMemDynOmp4 &&) -> BlockSharedMemDynOmp4 & = delete;
                    //-----------------------------------------------------------------------------
                    /*virtual*/ ~BlockSharedMemDynOmp4() = default;
                };

                namespace traits
                {
                    //#############################################################################
                    template<
                        typename T>
                    struct GetMem<
                        T,
                        BlockSharedMemDynOmp4>
                    {
                        //-----------------------------------------------------------------------------
                        static auto getMem(
                            block::shared::dyn::BlockSharedMemDynOmp4 const &)
                        -> T *
                        {
                            /*! dynamic shared memory does not appear to be
                            properly implemented in any other backend, so just
                            returning nullptr here to make it fail if used.
                            */
                            return nullptr;
                        }
                    };
                }
            }
        }
    }
}

#endif
