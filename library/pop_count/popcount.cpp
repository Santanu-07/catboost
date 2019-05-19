#include "popcount.h"

#include <util/system/defaults.h>
#include <util/system/yassert.h>

#include <string.h>

static const ui8 PopCountLUT8Impl[1 << 8] = {
#define B2(n) n, n + 1, n + 1, n + 2
#define B4(n) B2(n), B2(n + 1), B2(n + 1), B2(n + 2)
#define B6(n) B4(n), B4(n + 1), B4(n + 1), B4(n + 2)
    B6(0), B6(1), B6(1), B6(2)};

ui8 const* PopCountLUT8 = PopCountLUT8Impl;

#if !defined(_MSC_VER)
//ICE here for msvc

static const ui8 PopCountLUT16Impl[1 << 16] = {
#define B2(n) n, n + 1, n + 1, n + 2
#define B4(n) B2(n), B2(n + 1), B2(n + 1), B2(n + 2)
#define B6(n) B4(n), B4(n + 1), B4(n + 1), B4(n + 2)
#define B8(n) B6(n), B6(n + 1), B6(n + 1), B6(n + 2)
#define B10(n) B8(n), B8(n + 1), B8(n + 1), B8(n + 2)
#define B12(n) B10(n), B10(n + 1), B10(n + 1), B10(n + 2)
#define B14(n) B12(n), B12(n + 1), B12(n + 1), B12(n + 2)
    B14(0), B14(1), B14(1), B14(2)};

ui8 const* PopCountLUT16 = PopCountLUT16Impl;
#endif

#if defined(_x86_64_)
#include <util/system/cpu_id.h>

extern const bool HavePOPCNTInstr = NX86::HavePOPCNT();
#endif
