/* XMRig
 * Copyright 2010      Jeff Garzik <jgarzik@pobox.com>
 * Copyright 2012-2014 pooler      <pooler@litecoinpool.org>
 * Copyright 2014      Lucas Jones <https://github.com/lucasjones>
 * Copyright 2014-2016 Wolf9466    <https://github.com/OhGodAPet>
 * Copyright 2016      Jay D Dee   <jayddee246@gmail.com>
 * Copyright 2016-2017 XMRig       <support@xmrig.com>
 *
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __GPUTHREAD_H__
#define __GPUTHREAD_H__

#include <vector>


#include "nvidia/cryptonight.h"


class GpuThread
{
public:
    GpuThread();
    GpuThread(const nvid_ctx &ctx);
    ~GpuThread();

    bool init();
    void limit(int maxUsage, int maxThreads);

    static void autoConf(std::vector<GpuThread*> &threads, int bfactor, int bsleep);

    inline const char *name() const       { return m_name; }
    inline const int *arch() const        { return m_arch; }
    inline int bfactor() const            { return m_bfactor; }
    inline int blocks() const             { return m_blocks; }
    inline int bsleep() const             { return m_bsleep; }
    inline int clockRate() const          { return m_clockRate; } 
    inline int index() const              { return m_index; }
    inline int memoryClockRate() const    { return m_memoryClockRate; }
    inline int smx() const                { return m_smx; }
    inline int threadId() const           { return m_threadId; }
    inline int threads() const            { return m_threads; }

    inline void setBFactor(int bfactor)   { if (bfactor >= 0 && bfactor <= 12) { m_bfactor = bfactor; } }
    inline void setBlocks(int blocks)     { m_blocks = blocks; }
    inline void setBSleep(int bsleep)     { m_bsleep = bsleep; }
    inline void setIndex(int index)       { m_index = index; }
    inline void setThreadId(int threadId) { m_threadId = threadId; }
    inline void setThreads(int threads)   { m_threads = threads; }

private:
    bool m_affinity;
    char *m_name;
    int m_arch[2];
    int m_bfactor;
    int m_blocks;
    int m_bsleep;
    int m_clockRate;
    int m_index;
    int m_memoryClockRate;
    int m_smx;
    int m_threadId;
    int m_threads;
};


#endif /* __GPUTHREAD_H__ */
