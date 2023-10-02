// This file is autogenerated. To update it, run tools/generate_funcs.

#pragma once

#include "global/types.h"
#include "inject_util.h"

// clang-format off
#define g_ViewportAspectRatio VAR_I_(0x0046C304, float, 0.0f)
#define g_PhdWinTop VAR_U_(0x0046E310, int32_t)
#define g_FltWinBottom VAR_U_(0x0047031C, float)
#define g_PhdWinCenterX VAR_U_(0x00470330, int32_t)
#define g_PhdWinCenterY VAR_U_(0x00470334, int32_t)
#define g_FltWinTop VAR_U_(0x00470340, float)
#define g_FltWinLeft VAR_U_(0x00478048, float)
#define g_PhdWinMinY VAR_U_(0x0047804C, int16_t)
#define g_PhdFarZ VAR_U_(0x00478058, int32_t)
#define g_PhdWinBottom VAR_U_(0x00478060, int32_t)
#define g_PhdWinLeft VAR_U_(0x00478068, int32_t)
#define g_FltWinCenterX VAR_U_(0x004B2A00, float)
#define g_FltWinCenterY VAR_U_(0x004B2A04, float)
#define g_PhdWinMinX VAR_U_(0x004B2A10, int16_t)
#define g_MatrixPtr VAR_U_(0x004B2A28, struct MATRIX *)
#define g_Output_DrawObjectGT3 VAR_U_(0x004B2A2C, int16_t *(__cdecl *)(int16_t*, int32_t, enum SORT_TYPE))
#define g_Output_DrawObjectGT4 VAR_U_(0x004B2A30, int16_t *(__cdecl *)(int16_t*, int32_t, enum SORT_TYPE))
#define g_W2VMatrix VAR_U_(0x004B2AC0, struct MATRIX)
#define g_Output_DrawLine VAR_U_(0x004B2AF8, void(__cdecl *)(int32_t, int32_t, int32_t, int32_t, int32_t, uint8_t))
#define g_Output_DrawObjectG4 VAR_U_(0x004BCB08, int16_t *(__cdecl *)(int16_t*,int32_t, enum SORT_TYPE))
#define g_Output_DrawObjectG3 VAR_U_(0x004BCB50, int16_t *(__cdecl *)(int16_t*,int32_t, enum SORT_TYPE))
#define g_MatrixStack ARRAY_(0x004BCB58, struct MATRIX, [])
#define g_PhdVBuf ARRAY_(0x004BF3E0, struct PHD_VBUF, [1500])
#define g_FltWinRight VAR_U_(0x004D6B60, float)
#define g_PhdWinRight VAR_U_(0x004D6BF8, int32_t)
#define g_ErrorMessage ARRAY_(0x0051BD20, char, [128])
#define g_Items ARRAY_(0x005262F0, struct ITEM_INFO, [])
// clang-format on