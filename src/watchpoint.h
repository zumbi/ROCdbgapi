/* Copyright (c) 2020 Advanced Micro Devices, Inc.

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE. */

#ifndef AMD_DBGAPI_WATCHPOINT_H
#define AMD_DBGAPI_WATCHPOINT_H 1

#include "amd-dbgapi.h"
#include "handle_object.h"

namespace amd::dbgapi
{

class process_t;

/* AMD Debugger API Watchpoint.  */

class watchpoint_t : public detail::handle_object<amd_dbgapi_watchpoint_id_t>
{
public:
  watchpoint_t (amd_dbgapi_watchpoint_id_t watchpoint_id, process_t &process,
                amd_dbgapi_global_address_t requested_address,
                amd_dbgapi_size_t requested_size,
                amd_dbgapi_watchpoint_kind_t kind)
      : handle_object (watchpoint_id), m_requested_address (requested_address),
        m_requested_size (requested_size), m_kind (kind), m_process (process)
  {
  }
  ~watchpoint_t () {}

  amd_dbgapi_global_address_t requested_address () const
  {
    return m_requested_address;
  }
  amd_dbgapi_size_t requested_size () const { return m_requested_size; }
  amd_dbgapi_watchpoint_kind_t kind () const { return m_kind; }

  amd_dbgapi_status_t get_info (amd_dbgapi_watchpoint_info_t query,
                                size_t value_size, void *value) const;

  process_t &process () const { return m_process; }

private:
  const amd_dbgapi_global_address_t m_requested_address;
  const amd_dbgapi_size_t m_requested_size;
  const amd_dbgapi_watchpoint_kind_t m_kind;

  process_t &m_process;
};

} /* namespace amd::dbgapi */

#endif /* AMD_DBGAPI_WATCHPOINT_H */
