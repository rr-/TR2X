#pragma once

#include "global/types.h"

void __cdecl Item_InitialiseArray(int32_t num_items);
int16_t __cdecl Item_Create(void);
void __cdecl Item_Kill(int16_t item_num);
void __cdecl Item_Initialise(int16_t item_num);
void __cdecl Item_RemoveActive(int16_t item_num);
void __cdecl Item_RemoveDrawn(int16_t item_num);
void __cdecl Item_AddActive(int16_t item_num);
void __cdecl Item_NewRoom(int16_t item_num, int16_t room_num);
int32_t __cdecl Item_GlobalReplace(
    int32_t src_object_num, int32_t dst_object_num);
void __cdecl Item_ClearKilled(void);
bool Item_Teleport(ITEM_INFO *item, int32_t x, int32_t y, int32_t z);
void __cdecl Item_ShiftCol(ITEM_INFO *item, COLL_INFO *coll);
void __cdecl Item_UpdateRoom(ITEM_INFO *item, int32_t height);
int32_t __cdecl Item_TestBoundsCollide(
    const ITEM_INFO *src_item, const ITEM_INFO *dst_item, int32_t radius);
int32_t __cdecl Item_TestPosition(
    const int16_t *bounds, const ITEM_INFO *src_item,
    const ITEM_INFO *dst_item);
void __cdecl Item_AlignPosition(
    const XYZ_32 *vec, const ITEM_INFO *src_item, ITEM_INFO *dst_item);
void __cdecl Item_Animate(ITEM_INFO *item);
int32_t __cdecl Item_GetAnimChange(ITEM_INFO *item, const ANIM_STRUCT *anim);
void __cdecl Item_Translate(ITEM_INFO *item, int32_t x, int32_t y, int32_t z);
int32_t __cdecl Item_IsTriggerActive(ITEM_INFO *item);
int32_t __cdecl Item_GetFrames(
    const ITEM_INFO *item, FRAME_INFO *frmptr[], int32_t *rate);
BOUNDS_16 *__cdecl Item_GetBoundsAccurate(const ITEM_INFO *item);
FRAME_INFO *__cdecl Item_GetBestFrame(const ITEM_INFO *item);
bool __cdecl Item_IsNearItem(
    const ITEM_INFO *item, const XYZ_32 *pos, int32_t distance);

bool Item_IsSmashable(const ITEM_INFO *item);
void Item_TakeDamage(ITEM_INFO *item, int16_t damage, bool hit_status);
