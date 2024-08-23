#pragma once

#include "global/types.h"

int32_t __cdecl Gun_CheckForHoldingState(const LARA_STATE state);
void __cdecl Gun_TargetInfo(const WEAPON_INFO *winfo);
void __cdecl Gun_GetNewTarget(const WEAPON_INFO *winfo);
void __cdecl Gun_AimWeapon(const WEAPON_INFO *winfo, LARA_ARM *arm);
int32_t __cdecl Gun_FireWeapon(
    LARA_GUN_TYPE weapon_type, ITEM_INFO *target, const ITEM_INFO *src,
    const PHD_ANGLE *angles);
void __cdecl Gun_FindTargetPoint(const ITEM_INFO *item, GAME_VECTOR *target);
void __cdecl Gun_HitTarget(
    ITEM_INFO *item, const GAME_VECTOR *hit_pos, int32_t damage);
void __cdecl Gun_SmashItem(int16_t item_num, LARA_GUN_TYPE weapon_type);
