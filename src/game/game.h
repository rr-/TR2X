#pragma once

#include "global/types.h"

int32_t __cdecl Game_Control(int32_t nframes, bool demo_mode);
int32_t __cdecl Game_Draw(void);
int16_t __cdecl Game_Start(int32_t level_num, GF_LEVEL_TYPE level_type);
int32_t __cdecl Game_Loop(bool demo_mode);
